#include "GameUtilities.h"

using namespace jer;
using namespace std;

#include "SDLWrappers.h"
#include "ControlInterfaces.h"
#include "GameUtilities.h"

using namespace jer;
using namespace std;

using MyDisplayQueue = EasyDisplay;

class AppLoop: public Loopable, public Events
{
private:
    PhysicalEntity *entity;
    PhysicalObject *mouse;
    
public:
    virtual ~AppLoop() {if(mouse) delete mouse;};
    AppLoop(PhysicalEntity * const e): entity(e), mouse(NULL) {};
    
public:
    const SUCCESS loop() override 
    {
        SUCCESS ret = EventLoop::GetInstance().loop();
        if(mouse != NULL)
        {
            entity->gravitate(*mouse);
        }
        ret |= entity->loop();
        return ret;
    };
    
public:
    const SUCCESS mouseButtonPressed(const Uint32 window, const Uint32 mouse, const Uint8 button, const Uint8 clicks, const Point<int> &mPos)
    {
        if(button != SDL_BUTTON_LEFT || clicks != 1)
            return SUCCEEDED;
        
        if(this->mouse == NULL)
            this->mouse = new PhysicalObject(10.0, mPos);
        
        return SUCCEEDED;
    }
    
    const SUCCESS mouseButtonReleased(const Uint32 window, const Uint32 mouse, const Uint8 button, const Uint8 clicks, const Point<int> &mPos)
    {
        if(button != SDL_BUTTON_LEFT || clicks > 1)
            return SUCCEEDED;
        
        if(this->mouse != NULL)
            delete this->mouse;
        
        this->mouse = NULL;
        
        return SUCCEEDED;
    }
    
    const SUCCESS mouseMove(const Uint32 window, const Uint32 mouse, const Delta<Point<int> > &movement,
                            const bitset<N_MOUSE_BUTTONS> &buttons)
    {
        if(this->mouse == NULL)
            return SUCCEEDED;
        
        this->mouse->setPosition(movement.get());
        return SUCCEEDED;
    }
    
    const SUCCESS keyPressed(const Uint32 window, const SDL_Keysym &key)
    {
        if(key.scancode == SDL_SCANCODE_ESCAPE)
        {
            App::GetApp().stop();
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
    
    Texture *tex = new ScaledTexture(Texture(files->access<Surface>(string("test.png")), ren.get()), Dimensions<int>(50, 50));
    data->push_back(shared_ptr<Texture>(tex));
    
    MyDisplayQueue *displayer = new MyDisplayQueue;
    displayer->push_back(renWrap);
    
    PhysicalEntity *entity = new PhysicalEntity(tex, PhysicalObject(1.0, Point<double>(320, 240)));
    displayer->push_back(shared_ptr<PhysicalEntity>(entity));
    
    AppLoop *appLoop = new AppLoop(entity);
    Events::SetListener(appLoop);
    
    compProc.setLoader(data);
    compProc.setLooper(appLoop);
    compProc.setDisplayer(displayer);
    
    App::GetApp().setApp(&compProc);
    return App::GetApp().run();
}