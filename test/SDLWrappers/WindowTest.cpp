#include <stdlib.h>
#include <iostream>
#include <sstream>

#include "SDLWrappers.h"
#include "ControlInterfaces.h"

using namespace std;
using namespace jer;

class WindowSizeReporter: public Displayable, public Loopable
{
private:
    shared_ptr<Window> win;
    Runnable *runner;
    enum {NAME, POSITION, SIZE, ID, STAHP} counter;
    string query;
    int delay;
    
public:
    virtual ~WindowSizeReporter() {};
    WindowSizeReporter(const shared_ptr<Window>& w, Runnable * const r, const int d=0): win(w), runner(r), counter(NAME), delay(d) {};
    
public:
    const SUCCESS loop() override
    {
        stringstream ss;
        switch(counter)
        {
        case NAME:
            ss<<"Window is titled "<<win->getName();
            counter = POSITION;
            break;
        case POSITION:
            (ss<<"Window is at position ")<<win->getPosition();
            counter = SIZE;
            break;
        case SIZE:
            ss<<"Window has dimensions "<<win->getSize();
            counter = ID;
            break;
        case ID:
            ss<<"Window has ID "<<int(win->getID());
            counter = STAHP;
            break;
        case STAHP:
            runner->stop();
            break;
        default:
            return FAILED;
        }
        query = ss.str();
        SDL_Delay(delay);
        return SUCCEEDED;
    }
    
    const SUCCESS display() const override
    {
        cout<<query<<endl;
        return SUCCEEDED;
    }
};

int main(int argc, char **argv)
{
    CompositeProcess winProc;
    int delay = 500;
    if(argc >= 2)
        delay = atoi(argv[1]);
    shared_ptr<Window> win(new Window("WindowTest", 
                                      Point<int>(100, 100), Dimensions<int>(640, 480), 
                                      Window::RESIZABLE | Window::SHOWN));
    shared_ptr<WindowSizeReporter> winReporter(new WindowSizeReporter(win, &winProc, delay));
    winProc.setLoader(LoadWrapper(win));
    winProc.setLooper(LoopWrapper(winReporter));
    winProc.setDisplayer(DisplayWrapper(winReporter));
    App::GetApp().setApp(&winProc);
    return App::GetApp().run();
}