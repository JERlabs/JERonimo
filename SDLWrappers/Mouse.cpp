#include "Mouse.h"

namespace jer
{
    unordered_map<Uint32, Mouse *> Mouse::mouses;
    
    Mouse& Mouse::MutateMouse(const Uint32 id)
    {
        if(mouses.count(id))
            return *mouses[id];
        else
            return *(mouses[id] = new Mouse);
    }
    
    const Mouse& Mouse::GetMouse(const Uint32 id)
    {
        return MutateMouse(id);
    }
    
    const Mouse& Mouse::GetMouse()
    {
        return GetMouse(mouses.begin()->first);
    }
    
    void Mouse::ButtonEvent(SDL_MouseButtonEvent * const e)
    {
        if(e == NULL)   
            return;
        
        Mouse& m = MutateMouse(e->which);
        m.updateButton(e->button, e->state);
        m.updateFocus(e->windowID);
    }
    
    void Mouse::MotionEvent(SDL_MouseMotionEvent * const e)
    {
        if(e == NULL)
            return;
        
        Mouse& m = MutateMouse(e->which);
        m.updatePosition(Point<int>(e->x, e->y));
        m.updateFocus(e->windowID);
    }
    
    void Mouse::updateButton(const Uint8 butt, const bool state)
    {
        if(butt >= N_BUTTONS)
            return;
        buttonStates[butt] = state;
    }
}