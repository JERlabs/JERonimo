#include <vector>

#include "SDLWrappers.h"
#include "ControlInterfaces.h"

using namespace std;
using namespace jer;

class LoopDisplay: public Loopable, public Displayable
{
private:
    shared_ptr<Renderer> ren;
    vector<Point<int> > points;
    vector<Point<int> >::iterator current;
    Runnable *ender;
    
public:
    LoopDisplay(const shared_ptr<Renderer> &r, const vector<Point<int> > &p, Runnable * const end): ren(r), points(p), 
                                                                                                    current(points.begin()), ender(end)
    {
    }
    
public:
    const SUCCESS loop() override
    {
        SDL_SetRenderDrawColor(ren->getRenderer(), 255, 0, 0, 0);
        SUCCESS ret = SUCCEEDED;
        for(auto i = points.begin(); i != current; i++)
        {
            ret |= SDL_RenderDrawLine(ren->getRenderer(), i->x(), i->y(), (i+1)->x(), (i+1)->y());
        }
        
        if(++current == points.end())
            ender->stop();
        
        SDL_SetRenderDrawColor(ren->getRenderer(), 0, 0, 0, 0);
        
        return ret;
    }
    
    const SUCCESS display() const override
    {
        SDL_RenderPresent(ren->getRenderer());
        SDL_RenderClear(ren->getRenderer());
        SDL_Delay(500);
        return SUCCEEDED;
    }
};

int main(int argc, char **argv)
{
    CompositeProcess renProc;
    shared_ptr<Window> win(new Window("RendererTest", 
                                      Point<int>(100, 100), Dimensions<int>(640, 480),
                                      Window::SHOWN | Window::FULLSCREEN_DESKTOP));
    shared_ptr<HardRenderer> ren(new HardRenderer(win, true, true));
    renProc.setLoader(LoadWrapper(ren));
    vector<Point<int> > points;
    Point<int> next;
    for(int i = 1; i < argc; i += 2)
    {
        next.x(atoi(argv[i]));
        next.y(atoi(argv[i+1]));
        points.push_back(next);
    }
    shared_ptr<LoopDisplay> loopDisplayer(new LoopDisplay(ren, points, &renProc));
    renProc.setLooper(LoopWrapper(loopDisplayer));
    renProc.setDisplayer(DisplayWrapper(loopDisplayer));
    App::GetApp().setApp(&renProc);
    return App::GetApp().run();
}