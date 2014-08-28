#include "SDLWrappers.h"
#include "ControlInterfaces.h"
#include <vector>

using namespace std;
using namespace jer;

typedef CanvasRenderer<DrawOverRenderer<HardRenderer> > RenderType;

class Looper: public Loopable
{
private:
    shared_ptr<RenderType> ren;
    vector<Point<int> > points;
    vector<Point<int> >::iterator current;
    Runnable *ender;
    int shape;
    
public:
    Looper(const shared_ptr<RenderType > &r, const vector<Point<int> > &p, Runnable * const end): ren(r), points(p), 
    current(points.begin()), ender(end), shape(0)
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
        
        ren->setColor(Color(255, 0, 0, 0));
        SUCCESS ret;
        

        switch(shape % 4)
        {
        case 0:
            ret = ren->drawPoint(*(current-1));
            break;
        case 1:
            ret = ren->drawLine(Line<int>(*current, *(current-1)));
            break;
        case 2:
            ret = ren->drawRect(Rectangle<int>(Line<int>(*(current), *(current-1))));
            break;
        case 3:
            ret = ren->fillRect(Rectangle<int>(Line<int>(*(current), *(current-1))));
            break;
        }
        
        ren->setColor(Color(0, 0, 0, 0));
        
        current++;
        shape++;
        return ret;
    }
};

int main(int argc, char **argv)
{
    Logger<CompositeProcess> renProc;
    shared_ptr<Window> win(new Window("CanvasRendererTest", 
                                      Point<int>(100, 100), Dimensions<int>(640, 480),
                                      Window::SHOWN));
    shared_ptr<RenderType> ren(new RenderType(win, true, true));
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