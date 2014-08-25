#ifndef _EVENT_LOGGER_H_
#define _EVENT_LOGGER_H_

#include <iostream>
#include <string>

#include "Events.h"

namespace jer
{
    using std::ostream;
    using std::endl;
    using std::string;
    
    class EventLogger: public Events
    {
    private:
        ostream& out;
        
    public:
        EventLogger(ostream& o): out(o) {};
        EventLogger(): out(std::cout) {};
        
    private:
        static const string toString(const SDL_Keysym &key);
        
    public:
        virtual const SUCCESS mouseEnter(const Uint32 window) override;
        virtual const SUCCESS mouseLeave(const Uint32 window) override;
        virtual const SUCCESS keyboardFocusGain(const Uint32 window) override;
        virtual const SUCCESS keyboardFocusLost(const Uint32 window) override;
        virtual const SUCCESS minimized(const Uint32 window) override;
        virtual const SUCCESS restored(const Uint32 window) override;
        virtual const SUCCESS maximized(const Uint32 window) override;
        virtual const SUCCESS resized(const Uint32 window, const Dimensions<int> &size) override;
        virtual const SUCCESS moved(const Uint32 window, const Point<int> &pos) override;
        virtual const SUCCESS exposed(const Uint32 window) override;
        virtual const SUCCESS shown(const Uint32 window) override;
        virtual const SUCCESS hidden(const Uint32 window) override;
        virtual const SUCCESS windowExited(const Uint32 window) override;
        
        virtual const SUCCESS keyHeld(const Uint32 window, const SDL_Keysym &key) override;
        virtual const SUCCESS keyPressed(const Uint32 window, const SDL_Keysym &key) override;
        virtual const SUCCESS keyReleased(const Uint32 window, const SDL_Keysym &key) override;
        
        virtual const SUCCESS textInput(const Uint32 window, const char * const text) override;
        virtual const SUCCESS textEdit(const Uint32 window, const char * const text, const int start, const int length) override;
        
        virtual const SUCCESS mouseMove(const Uint32 window, const Uint32 mouse, const Delta<Point<int> > &movement,
                                        const bitset<N_MOUSE_BUTTONS> &buttons) override;
                                        
        virtual const SUCCESS mouseButtonPressed(const Uint32 window, const Uint32 mouse,
                                                 const Uint8 button, const Uint8 clicks, const Point<int> &mPos) override;
        virtual const SUCCESS mouseButtonReleased(const Uint32 window, const Uint32 mouse,
                                                 const Uint8 button, const Uint8 clicks, const Point<int> &mPos) override;
        virtual const SUCCESS mouseWheel(const Uint32 window, const Uint32 mouse, const Point<int> &scroll) override;
        
        virtual const SUCCESS joyAxis(const SDL_JoystickID stick, const Uint8 axis, const Sint16 value) override;
        
        virtual const SUCCESS joyButtonPressed(const SDL_JoystickID stick, const Uint8 button) override;
        virtual const SUCCESS joyButtonReleased(const SDL_JoystickID stick, const Uint8 button) override;
        
        virtual const SUCCESS joyHatChange(const SDL_JoystickID stick, const Uint8 hat, const Uint8 position) override;
        
        virtual const SUCCESS joyBallMove(const SDL_JoystickID stick, const Uint8 ball, const Point<Sint16> &rel) override;
        
        virtual const SUCCESS joyAdded(const Sint32 device) override;
        virtual const SUCCESS joyRemoved(const Sint32 id) override;
        
        virtual const SUCCESS droppedFile(const char * const file) override;
        
        virtual const SUCCESS unhandledSystemEvent(SDL_SysWMmsg * const msg) override;
        
        virtual const SUCCESS userEvent(const Uint32 window, const int code, void * const data1, void * const data2) override;
    };
}


#endif /*_EVENT_LOGGER_H_*/