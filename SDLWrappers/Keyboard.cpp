#include "Keyboard.h"


namespace jer
{
    Keyboard Keyboard::keyboard;
    
    void Keyboard::KeyEvent(SDL_KeyboardEvent * const e)
    {
        if(e == NULL)
            return;
        
        keyboard.updateKey(e->keysym.scancode, e->state == SDL_PRESSED? 1:0);
        keyboard.updateMod(e->keysym.mod);
        keyboard.updateFocus(e->windowID);
    }
    
    void Keyboard::TextInputEvent(SDL_TextInputEvent * const e)
    {
        if(e == NULL)
            return;
        
        keyboard.updateText() += e->text;
    }
    
    void Keyboard::TextEditingEvent(SDL_TextEditingEvent * const e)
    {
        if(e == NULL)
            return;
        
        keyboard.updateText() = e->text;
    }
}