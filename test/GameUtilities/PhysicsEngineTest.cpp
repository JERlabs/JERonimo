#include "Space2D.h"
#include "GameUtilities.h"
#include "ControlInterfaces.h"
#include "SDLWrappers.h"

using namespace std;
using namespace jer;

class EventHandler: public Events
{
private:
	PhysicsEngine * world;
	EasyDisplay * displayer;
	const Texture& image;
	shared_ptr<PhysicalEntity> current;
	
public:
	virtual ~EventHandler() {};
	EventHandler(PhysicsEngine * const w, EasyDisplay * const d, const Texture& img): world(w), displayer(d), image(img), current(nullptr) {};
	
public:
	const SUCCESS mouseButtonPressed(const Uint32 window, const Uint32 mouse, const Uint8 button, const Uint8 clicks, const Point<int> &mPos)
    {
        if(button != SDL_BUTTON_LEFT || clicks != 1)
            return SUCCEEDED;
        
        current.reset(new PhysicalEntity(new ScaledTexture(image, Dimensions<int>(100, 100)), PhysicalObject(100.0, mPos, new RectangleCollidable(Rectangle<double>(Point<double>(-50, -50), Dimensions<double>(100, 100))))));
        displayer->push_back(current);
        return SUCCEEDED;
    }
    
    const SUCCESS mouseButtonReleased(const Uint32 window, const Uint32 mouse, const Uint8 button, const Uint8 clicks, const Point<int> &mPos)
    {
        if(button != SDL_BUTTON_LEFT || clicks > 1 || current == nullptr)
            return SUCCEEDED;
        
		Dimensions<double> d(Point<double>(mPos)-(current->getPosition()));
        current->setImage(new ScaledTexture(image, d*2.0));
		current->setMass(100*pythagoras(d*2.0));
		world->push_back(current);
        current.reset();
        return SUCCEEDED;
    }
    
    const SUCCESS mouseMove(const Uint32 window, const Uint32 mouse, const Delta<Point<int> > &movement,
                            const bitset<N_MOUSE_BUTTONS> &buttons)
    {
        if(current == nullptr)
            return SUCCEEDED;
        
		Dimensions<double> d(Point<double>(movement.get())-current->getPosition());
        current->setImage(new ScaledTexture(image, d*2.0));
		current->getCollider()->setOffset(Point<double>(-abs(d.x()), -abs(d.y())));
		current->getCollider()->setDimensions(d*2.0);
		current->setVelocity(Vector(Mag_t<double>(0.0), getTheta(d)));
        return SUCCEEDED;
    }
	
	const SUCCESS keyPressed(const Uint32 window, const SDL_Keysym &key)
	{
		if(key.scancode == SDL_SCANCODE_Z && current == nullptr)
		{
			cout<<"Undoing"<<endl;
			if(displayer->size() > 1)
			{
				displayer->pop_back();
				world->pop_back();
			}
		}
		return SUCCEEDED;
	}
};

int main(int argc, char **argv)
{
	string image(argc > 1? argv[1]:"test.png");
	
	CompositeProcess compProc;
    EasyData *data = new EasyData;
    
    FileManager *files = new FileManager;
    data->push_back(shared_ptr<FileManager>(files));
    
    shared_ptr<Window> win(new Window("Physics Woah", Point<int>(0, 0), Dimensions<int>(640, 480), Window::SHOWN | Window::RESIZABLE));
    shared_ptr<RedrawRenderer<HardRenderer> > ren(new RedrawRenderer<HardRenderer>(win, true, true));
    data->push_back(win);
    data->push_back(ren);
    
    Texture *tex = new Texture(files->access<Surface>(image), ren.get());
    data->push_back(shared_ptr<Texture>(tex));
    
    EasyDisplay *displayer = new EasyDisplay;
    displayer->push_back(ren);
	
	PhysicsEngine *engine = new PhysicsEngine();
	EasyLoop *looper = new EasyLoop();
	looper->push_back(EventLoop::GetReference());
    looper->push_back(shared_ptr<PhysicsEngine>(engine));
	
	EventHandler handler(engine, displayer, *tex);
    Events::SetListener(&handler);
    
    compProc.setLoader(data);
    compProc.setLooper(looper);
    compProc.setDisplayer(displayer);
    
    App::GetApp().setApp(&compProc);
    return App::GetApp().run();	
	
}





