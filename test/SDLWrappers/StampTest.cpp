#include "SDLWrappers.h"
#include "ControlInterfaces.h"
#include "GameUtilities.h"

using namespace jer;
using namespace std;

using MyDisplayQueue = DisplayQueue<DisplayWrapper, SortList<DisplayWrapper> > ;

class AppLoop: public Loopable, public Events
{
private:
    const Texture &stamp;
    Entity *current;
    MyDisplayQueue *displayer;
    
public:
    virtual ~AppLoop() {};
    AppLoop(const Texture &s, MyDisplayQueue *d): stamp(s), current(NULL), displayer(d) {};
    
public:
    const SUCCESS loop() override 
	{
		displayer->sort();
		return EventLoop::GetInstance().loop();
	};
    
public:
    const SUCCESS mouseButtonPressed(const Uint32 window, const Uint32 mouse, const Uint8 button, const Uint8 clicks, const Point<int> &mPos)
    {
        if(button != SDL_BUTTON_LEFT || clicks != 1)
            return SUCCEEDED;
        
        current = new Entity(new ScaledTexture(stamp, Dimensions<int>(1, 1)), mPos);
        displayer->push_back(PriorityControlElement<DisplayWrapper>(shared_ptr<Displayable>(current), displayer->size()));
        return SUCCEEDED;
    }
    
    const SUCCESS mouseButtonReleased(const Uint32 window, const Uint32 mouse, const Uint8 button, const Uint8 clicks, const Point<int> &mPos)
    {
        if(button != SDL_BUTTON_LEFT || clicks > 1 || current == NULL)
            return SUCCEEDED;
        
        current->setImage(new ScaledTexture(stamp, mPos-current->getPixelPosition()));
        current = NULL;
        return SUCCEEDED;
    }
    
    const SUCCESS mouseMove(const Uint32 window, const Uint32 mouse, const Delta<Point<int> > &movement,
                            const bitset<N_MOUSE_BUTTONS> &buttons)
    {
        if(current == NULL)
            return SUCCEEDED;
        
        current->setImage(new ScaledTexture(stamp, movement.get()-current->getPixelPosition()));
        return SUCCEEDED;
    }
	
	const SUCCESS keyPressed(const Uint32 window, const SDL_Keysym &key)
	{
		if(key.scancode == SDL_SCANCODE_Z && current == NULL)
		{
			cout<<"Undoing"<<endl;
			if(displayer->size() > 1)
			displayer->pop_back();
		}
		return SUCCEEDED;
	}
    
};

int main(int argc, char **argv)
{
    CompositeProcess compProc;
    EasyData *data = new EasyData;
    
    FileManager *files = new FileManager;
    data->push_back(shared_ptr<FileManager>(files));
    
    shared_ptr<Window> win(new Window("Stamps Woah", Point<int>(0, 0), Dimensions<int>(640, 480), Window::SHOWN | Window::RESIZABLE));
    shared_ptr<RedrawRenderer<HardRenderer> > ren(new RedrawRenderer<HardRenderer>(win, true, true));
    PriorityControlElement<DisplayWrapper> renWrap(shared_ptr<Displayable>(ren), 0);
    data->push_back(win);
    data->push_back(ren);
    
    Texture *tex = new Texture(files->access<Surface>(string("test.png")), ren.get());
    data->push_back(shared_ptr<Texture>(tex));
    
    MyDisplayQueue *displayer = new MyDisplayQueue;
    displayer->push_back(renWrap);
    
    AppLoop *appLoop = new AppLoop(*tex, displayer);
    Events::SetListener(appLoop);
    
    compProc.setLoader(data);
    compProc.setLooper(appLoop);
    compProc.setDisplayer(displayer);
    
    App::GetApp().setApp(&compProc);
    return App::GetApp().run();
}