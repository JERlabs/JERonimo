#include "SDLWrappers.h"
#include "ControlInterfaces.h"

using namespace std;
using namespace jer;

int main(int argc, char **argv)
{
    shared_ptr<DrawOverRenderer<HardRenderer> > ren(new DrawOverRenderer<HardRenderer>(shared_ptr<Window>(new Window("Events Test", Point<int>(100, 100), Dimensions<int>(640, 480),
                                                             Window::SHOWN | Window::RESIZABLE)), true, true));
    Logger<CompositeProcess> eventProc;
    eventProc.setLoader(LoadWrapper(ren));
    eventProc.setLooper(LoopWrapper(EventLoop::GetReference()));
    eventProc.setDisplayer(DisplayWrapper(ren));
    
    EventLogger eventListener;
    
    Events::SetListener(&eventListener);
    App::GetApp().setApp(&eventProc);
    
    return App::GetApp().run();
}