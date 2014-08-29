#include "SDLWrappers.h"
#include "ControlInterfaces.h"

using namespace std;
using namespace jer;

typedef CanvasRenderer<DrawOverRenderer<HardRenderer> > RenderType;

class AppLoop: public SimpleProcess, public Events
{
private:
    RenderType ren;
    Color col;
    Point<int> prev;
    
public:
    AppLoop(): ren(shared_ptr<Window>(new Window("Linux Paint", Point<int>(0, 0), Dimensions<int>(640, 480), Window::SHOWN | Window::RESIZABLE)),
                   true, true), col(255, 255, 255, 255)
    {
        Events::SetListener(this);
    };
    virtual ~AppLoop() {if(isLoaded()) unload();};
    
public:
    const SUCCESS load() override
    {
        SUCCESS ret;
        if((ret = ren.load()) >= SUCCEEDED)
            Loadable::load();
        ret |= ren.setColor(col);
        ret |= ren.clear();
        return ret;
    };
    
    const SUCCESS unload() override
    {
        Loadable::unload();
        return ren.unload();
    };
    
    const SUCCESS loop() override
    {
        return EventLoop::GetInstance().loop();
    };
    
    const SUCCESS display() const override
    {
        return ren.display();
    };
    
    const SUCCESS mouseMove(const Uint32 window, const Uint32 mouse, const Delta<Point<int> > &movement,
                            const bitset<N_MOUSE_BUTTONS> &buttons) override
    {
        SUCCESS ret = SUCCEEDED;
        if(window == ren.getWin()->getID() && buttons[SDL_BUTTON_LEFT-1])
            ret = ren.drawLine(Line<int>(movement.get(), prev));
        prev = movement.get();
        return ret;
    };
    
    const SUCCESS changeSize(const Uint32 window) override
    {
        ren.setColor(Color(255, 255, 255, 0));
        ren.clear();
        ren.setColor(col);
        return SUCCEEDED;
    }
    
    const SUCCESS mouseButtonPressed(const Uint32 window, const Uint32 mouse, 
                                     const Uint8 button, const Uint8 clicks, const Point<int> &mPos) override
    {
        if(window != ren.getWin()->getID())
            return SUCCEEDED;
            
        if(clicks == 1 && button == SDL_BUTTON_LEFT)
            return ren.drawPoint(prev = mPos);
        else if(clicks == 1 && button == SDL_BUTTON_RIGHT)
            return ren.clear();
        return SUCCEEDED;
    };
    
    const SUCCESS mouseWheel(const Uint32 window, const Uint32 mouse, const Point<int> &scroll)
    {
        if(window != ren.getWin()->getID())
            return SUCCEEDED;
        return SUCCEEDED;
    };
    
private:
    const SUCCESS colorChange(const SDL_Keysym &key)
    {
        switch(key.scancode)
        {
        default:
            return SUCCEEDED;
        case SDL_SCANCODE_Q:
            col.R()++;
            break;
        case SDL_SCANCODE_W:
            col.G()++;
            break;
        case SDL_SCANCODE_E:
            col.B()++;
            break;
        case SDL_SCANCODE_R:
            col.A()++;
            break;
        case SDL_SCANCODE_A:
            col.R()--;
            break;
        case SDL_SCANCODE_S:
            col.G()--;
            break;
        case SDL_SCANCODE_D:
            col.B()--;
            break;
        case SDL_SCANCODE_F:
            col.A()--;
            break;
        }
        
        ren.setColor(col);
        return SUCCEEDED;
    }
    
public:
    const SUCCESS keyPressed(const Uint32 window, const SDL_Keysym &key) override
    {
        if(window != ren.getWin()->getID())
            return SUCCEEDED;
        switch(key.scancode)
        {
        case SDL_SCANCODE_ESCAPE:
            stop();
            break;
        default:
            return colorChange(key);
        }
        
        return SUCCEEDED;
    };
    
    const SUCCESS keyHeld(const Uint32 window, const SDL_Keysym &key) override
    {
        if(window != ren.getWin()->getID())
            return SUCCEEDED;
        
        switch(key.scancode)
        {
        default:
            return colorChange(key);
        }
        
        return SUCCEEDED;
    }
    
    
};


int main(int argc, char **argv)
{
    Logger<AppLoop> myApp;
    App::GetApp().setApp(&myApp);
    return App::GetApp().run();
}