#include "Mouse.h"

namespace jer
{
    unordered_map<Uint32, shared_ptr<Mouse> > Mouse::mouses;
    
    Mouse& Mouse::MutateMouse(const Uint32 id)
    {
        shared_ptr<Mouse> &ptr = mouses[id];
        if(ptr == nullptr)
            ptr.reset(new Mouse);
        return *ptr;
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
}