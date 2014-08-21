#ifndef _KEYBOARD_H_
#define _KEYBOARD_H_

#include <bitset>
#include <string>

#include "Declarations.h"
#include "App.h"
#include "Window.h"

namespace jer
{
    using std::bitset;
    using std::string;
    
    class Keyboard
    {
    public:
        enum {N_SCANCODES=SDL_NUM_SCANCODES};
        enum {N_MODCODES=KMOD_GUI};
        
    private:
        static Keyboard keyboard;
        
    public:
        static const Keyboard& GetKeyboard() {return keyboard;};
        
    private:
        static void KeyEvent(SDL_KeyboardEvent * const e);
        static void TextInputEvent(SDL_TextInputEvent * const e);
        static void TextEditingEvent(SDL_TextEditingEvent * const e);
        
    private:
        bitset<N_SCANCODES> scanStates;
        bitset<N_MODCODES> modStates;
        string text;
        Window *keyboardFocus;
        
    private:
        ~Keyboard() {};
        Keyboard(): text(31, '\0'), keyboardFocus(NULL) {};
        
    public:
        const bool getKeyScan(const Uint16 scancode) const {return scancode >= N_SCANCODES? false:scanStates[scancode];};
        const bool getMod(const Uint8 mod) const {return mod >= N_MODCODES? false:modStates[mod];};
        const string& getText() const {return text;};
        Window * const getFocusedWindow() const {return keyboardFocus;};
        
    private:
        void updateKey(const Uint16 scan, const bool state);
        void updateMod(const Uint8 mod, const bool state);
        void updateMod(const Uint16 mod);
        void updateText(const string &t) {text = t;};
        string &updateText() {return text;};
        void updateFocus(Window * const win) {keyboardFocus = win;};
        void updateFocus(const Uint32 winID) {keyboardFocus = Window::GetWindow(winID);};
    };
}



#endif /*_KEYBOARD_H_*/