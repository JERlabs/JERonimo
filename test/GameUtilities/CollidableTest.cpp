#include "GameUtilities.h"
#include "ControlInterfaces.h"
#include "SDLWrappers.h"

using namespace std;
using namespace jer;

class AppLoop: public Loopable, public Events
{
private:
    PhysicalEntity *entity1;
    PhysicalEntity *entity2;
    
public:
    virtual ~AppLoop() {};
    AppLoop(PhysicalEntity * const e1, PhysicalEntity * const e2): entity1(e1), entity2(e2) {};
    
public:
    const SUCCESS loop() override
    {
        SUCCESS ret = EventLoop::GetInstance().loop();
        entity1->gravitate(*entity2);
        entity2->gravitate(*entity1);
        entity1->checkCollision(*entity2);
        
        ret |= entity1->loop() | entity2->loop();
        return ret;
    }
};

int main(int argc, char **argv)
{
    CompositeProcess compProc;
    EasyData *data = new EasyData;
    
    FileManager *files = new FileManager;
    data->push_back(shared_ptr<FileManager>(files));
    
    shared_ptr<Window> win(new Window("Testing collision", Point<int>(0, 0), Dimensions<int>(640, 480), Window::SHOWN | Window::RESIZABLE));
    shared_ptr<RedrawRenderer<HardRenderer> > ren(new RedrawRenderer<HardRenderer>(win, true, true));   
    data->push_back(win);
    data->push_back(ren);
    
    shared_ptr<Texture> tex(new ScaledTexture(Texture(files->access<Surface>(string("test.png")), ren.get()), Dimensions<int>(50, 50)));
    shared_ptr<Texture> tex2(new ScaledTexture(tex.get(), Dimensions<int>(100, 100)));
    data->push_back(tex);
    data->push_back(tex2);
    
    EasyDisplay *displayer = new EasyDisplay;
    displayer->push_back(ren);
    
    PhysicalEntity *entity1 = new PhysicalEntity(tex2, PhysicalObject(10.0, Point<double>(100, 240), Vector(Mag_t<double>(0.3), Degrees(0.0)), new RectangleCollidable(Rectangle<double>(Point<double>(-25.0, -25.0), Dimensions<double>(50.0, 50.0)))));
    PhysicalEntity *entity2 = new PhysicalEntity(tex, PhysicalObject(1.0, Point<double>(300, 240), new RectangleCollidable(Rectangle<double>(Point<double>(-50.0, -50.0), Dimensions<double>(100.0, 100.0)))));
    
    displayer->push_back(shared_ptr<PhysicalEntity>(entity1));
    displayer->push_back(shared_ptr<PhysicalEntity>(entity2));
    
    AppLoop *appLoop = new AppLoop(entity1, entity2);
    Events::SetListener(appLoop);
    
    compProc.setLoader(data);
    compProc.setLooper(appLoop);
    compProc.setDisplayer(displayer);
    
    App::GetApp().setApp(&compProc);
    return App::GetApp().run();    
}