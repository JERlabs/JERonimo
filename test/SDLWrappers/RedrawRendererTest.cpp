#include <vector>

#include "SDLWrappers.h"
#include "ControlInterfaces.h"

using namespace std;
using namespace jer;

class Looper: public Loopable
{
private:
    shared_ptr<Renderer> ren;
    vector<Point<int> > points;
    vector<Point<int> >::iterator current;
    Runnable *ender;
    
public:
    Looper(const shared_ptr<Renderer> &r, const vector<Point<int> > &p, Runnable * const end): ren(r), points(p), 
                                                                                                    current(points.begin()), ender(end)
    {
    }
    
public:
    const SUCCESS loop() override
    {
        if(current == points.begin())
        {
            current++;
            return SUCCEEDED;
        }
        SDL_Delay(500);
        if(current == points.end())
        {
            ender->stop();
            return SUCCEEDED;
        }
        
        SDL_SetRenderDrawColor(ren->getRenderer(), 255, 0, 0, 0);
        SUCCESS ret = SDL_RenderDrawLine(ren->getRenderer(), (current-1)->x(), (current-1)->y(), (current)->x(), (current)->y());
        
        SDL_SetRenderDrawColor(ren->getRenderer(), 0, 0, 0, 0);
       
        current++;
        return ret;
    }
};

int main(int argc, char **argv)
{
    CompositeProcess renProc;
    shared_ptr<Window> win(new Window("RendererTest", 
                                      Point<int>(100, 100), Dimensions<int>(640, 480),
                                      Window::SHOWN));
    shared_ptr<RedrawRenderer<HardRenderer> > ren(new RedrawRenderer<HardRenderer>(win, true, true));
    renProc.setLoader(LoadWrapper(ren));
    vector<Point<int> > points;
    Point<int> next;
    for(int i = 1; i < argc; i += 2)
    {
        next.x(atoi(argv[i]));
        next.y(atoi(argv[i+1]));
        points.push_back(next);
    }
    shared_ptr<Looper> myLooper(new Looper(ren, points, &renProc));
    renProc.setLooper(LoopWrapper(myLooper));
    renProc.setDisplayer(DisplayWrapper(ren));
    App::GetApp().setApp(&renProc);
    return App::GetApp().run();
}