#include "EventLogger.h"

namespace jer
{
    const string EventLogger::toString(const SDL_Keysym &key)
    {
        string ret("");
        switch(key.scancode)
        {
        case SDL_SCANCODE_0:
            ret += '0';
            break;
        case SDL_SCANCODE_1:
            ret += '1';
            break;
        case SDL_SCANCODE_2:
            ret += '2';
            break;
        case SDL_SCANCODE_3:
            ret += '3';
            break;
        case SDL_SCANCODE_4:
            ret += '4';
            break;
        case SDL_SCANCODE_5:
            ret += '5';
            break;
        case SDL_SCANCODE_6:
            ret += '6';
            break;
        case SDL_SCANCODE_7:
            ret += '7';
            break;
        case SDL_SCANCODE_8:
            ret += '8';
            break;
        case SDL_SCANCODE_9:
            ret += '9';
            break;
        case SDL_SCANCODE_A:
            ret += 'A';
            break;
        case SDL_SCANCODE_B:
            ret += 'B';
            break;
        case SDL_SCANCODE_C:
            ret += 'C';
            break;
        case SDL_SCANCODE_D:
            ret += 'D';
            break;
        case SDL_SCANCODE_E:
            ret += 'E';
            break;
        case SDL_SCANCODE_F:
            ret += 'F';
            break;
        case SDL_SCANCODE_G:
            ret += 'G';
            break;
        case SDL_SCANCODE_H:
            ret += 'H';
            break;
        case SDL_SCANCODE_I:
            ret += 'I';
            break;
        case SDL_SCANCODE_J:
            ret += 'J';
            break;
        case SDL_SCANCODE_K:
            ret += 'K';
            break;
        case SDL_SCANCODE_L:
            ret += 'L';
            break;
        case SDL_SCANCODE_M:
            ret += 'M';
            break;
        case SDL_SCANCODE_N:
            ret += 'N';
            break;
        case SDL_SCANCODE_O:
            ret += 'O';
            break;
        case SDL_SCANCODE_P:
            ret += 'P';
            break;
        case SDL_SCANCODE_Q:
            ret += 'Q';
            break;
        case SDL_SCANCODE_R:
            ret += 'R';
            break;
        case SDL_SCANCODE_S:
            ret += 'S';
            break;
        case SDL_SCANCODE_T:
            ret += 'T';
            break;
        case SDL_SCANCODE_U:
            ret += 'U';
            break;
        case SDL_SCANCODE_V:
            ret += 'V';
            break;
        case SDL_SCANCODE_W:
            ret += 'W';
            break;
        case SDL_SCANCODE_X:
            ret += 'X';
            break;
        case SDL_SCANCODE_Y:
            ret += 'Y';
            break;
        case SDL_SCANCODE_Z:
            ret += 'Z';
            break;
        case SDL_SCANCODE_AC_BACK:
            ret += "AC Back";
            break;
        case SDL_SCANCODE_AC_BOOKMARKS:
            ret += "AC Bookmarks";
            break;
        case SDL_SCANCODE_AC_FORWARD:
            ret += "AC Forward";
            break;
        case SDL_SCANCODE_AC_HOME:
            ret += "AC Home";
            break;
        case SDL_SCANCODE_AC_REFRESH:
            ret += "AC Refresh";
            break;
        case SDL_SCANCODE_AC_SEARCH:
            ret += "AC Search";
            break;
        case SDL_SCANCODE_AC_STOP:
            ret += "AC Stop";
            break;
        case SDL_SCANCODE_AGAIN:
            ret += "Again";
            break;
        case SDL_SCANCODE_ALTERASE:
            ret += "Alt Erase";
            break;
        case SDL_SCANCODE_APOSTROPHE:
            ret += '\'';
            break;
        case SDL_SCANCODE_APPLICATION:
            ret += "Application Key";
            break;
        case SDL_SCANCODE_AUDIOMUTE:
            ret += "Audio Muted";
            break;
        case SDL_SCANCODE_AUDIONEXT:
            ret += "Audio Next";
            break;
        case SDL_SCANCODE_AUDIOPLAY:
            ret += "Audio Play";
            break;
        case SDL_SCANCODE_AUDIOPREV:
            ret += "Audio Prev";
            break;
        case SDL_SCANCODE_AUDIOSTOP:
            ret += "Audio Stop";
            break;
        case SDL_SCANCODE_BACKSLASH:
            ret += '\\';
            break;
        case SDL_SCANCODE_BACKSPACE:
            ret += "Backspace";
            break;
        case SDL_SCANCODE_BRIGHTNESSDOWN:
            ret += "Brightness Down";
            break;
        case SDL_SCANCODE_BRIGHTNESSUP:
            ret += "Brightness Up";
            break;
        case SDL_SCANCODE_CALCULATOR:
            ret += "Calculator";
            break;
        case SDL_SCANCODE_CANCEL:
            ret += "Cancel";
            break;
        case SDL_SCANCODE_CAPSLOCK:
            ret += "Caps Lock";
            break;
        case SDL_SCANCODE_CLEAR:
            ret += "Clear";
            break;
        case SDL_SCANCODE_CLEARAGAIN:
            ret += "Clear/Again";
            break;
        case SDL_SCANCODE_COMMA:
            ret += ',';
            break;
        case SDL_SCANCODE_COMPUTER:
            ret += "Computer";
            break;
        case SDL_SCANCODE_COPY:
            ret += "Copy";
            break;
        case SDL_SCANCODE_CRSEL:
            ret += "CrSel";
            break;
        case SDL_SCANCODE_CURRENCYSUBUNIT:
            ret += "Currency Sub Unit";
            break;
        case SDL_SCANCODE_CUT:
            ret += "Cut";
            break;
        case SDL_SCANCODE_DECIMALSEPARATOR:
            ret += "Decimal Separator";
            break;
        case SDL_SCANCODE_DELETE:
            ret += "Delete";
            break;
        case SDL_SCANCODE_DISPLAYSWITCH:
            ret += "Display Switch";
            break;
        case SDL_SCANCODE_DOWN:
            ret += "Down";
            break;
        case SDL_SCANCODE_EJECT:
            ret += "Eject";
            break;
        case SDL_SCANCODE_END:
            ret += "End";
            break;
        case SDL_SCANCODE_EQUALS:
            ret += '=';
            break;
        case SDL_SCANCODE_ESCAPE:
            ret += "Esc";
            break;
        case SDL_SCANCODE_EXECUTE:
            ret += "Execute";
            break;
        case SDL_SCANCODE_EXSEL:
            ret += "ExSel";
            break;
        case SDL_SCANCODE_F1:
            ret += "F1";
            break;
        case SDL_SCANCODE_F2:
            ret += "F2";
            break;
        case SDL_SCANCODE_F3:
            ret += "F3";
            break;
        case SDL_SCANCODE_F4:
            ret += "F4";
            break;
        case SDL_SCANCODE_F5:
            ret += "F5";
            break;
        case SDL_SCANCODE_F6:
            ret += "F6";
            break;
        case SDL_SCANCODE_F7:
            ret += "F7";
            break;
        case SDL_SCANCODE_F8:
            ret += "F8";
            break;
        case SDL_SCANCODE_F9:
            ret += "F9";
            break;
        case SDL_SCANCODE_F10:
            ret += "F10";
            break;
        case SDL_SCANCODE_F11:
            ret += "F11";
            break;
        case SDL_SCANCODE_F12:
            ret += "F12";
            break;
        case SDL_SCANCODE_F13:
            ret += "F13";
            break;
        case SDL_SCANCODE_F14:
            ret += "F14";
            break;
        case SDL_SCANCODE_F15:
            ret += "F15";
            break;
        case SDL_SCANCODE_F16:
            ret += "F16";
            break;
        case SDL_SCANCODE_F17:
            ret += "F17";
            break;
        case SDL_SCANCODE_F18:
            ret += "F18";
            break;
        case SDL_SCANCODE_F19:
            ret += "F19";
            break;
        case SDL_SCANCODE_F20:
            ret += "F20";
            break;
        case SDL_SCANCODE_F21:
            ret += "F21";
            break;
        case SDL_SCANCODE_F22:
            ret += "F22";
            break;
        case SDL_SCANCODE_F23:
            ret += "F23";
            break;
        case SDL_SCANCODE_F24:
            ret += "F24";
            break;
        case SDL_SCANCODE_FIND:
            ret += "Find";
            break;
        case SDL_SCANCODE_GRAVE:
            ret += '`';
            break;
        case SDL_SCANCODE_HELP:
            ret += "Help";
            break;
        case SDL_SCANCODE_HOME:
            ret += "Home";
            break;
        case SDL_SCANCODE_INSERT:
            ret += "Insert";
            break;
        case SDL_SCANCODE_KBDILLUMDOWN:
            ret += "Keyboard Illumination Down";
            break;
        case SDL_SCANCODE_KBDILLUMTOGGLE:
            ret += "Keyboard Illumination Toggle";
            break;
        case SDL_SCANCODE_KBDILLUMUP:
            ret += "Keyboard Illumination Up";
            break;
        case SDL_SCANCODE_KP_0:
            ret += "Keypad 0";
            break;
        case SDL_SCANCODE_KP_00:
            ret += "Keypad 00";
            break;
        case SDL_SCANCODE_KP_000:
            ret += "Keypad 000";
            break;
        case SDL_SCANCODE_KP_1:
            ret += "Keypad 1";
            break;
        case SDL_SCANCODE_KP_2:
            ret += "Keypad 2";
            break;
        case SDL_SCANCODE_KP_3:
            ret += "Keypad 3";
            break;
        case SDL_SCANCODE_KP_4:
            ret += "Keypad 4";
            break;
        case SDL_SCANCODE_KP_5:
            ret += "Keypad 5";
            break;
        case SDL_SCANCODE_KP_6:
            ret += "Keypad 6";
            break;
        case SDL_SCANCODE_KP_7:
            ret += "Keypad 7";
            break;
        case SDL_SCANCODE_KP_8:
            ret += "Keypad 8";
            break;
        case SDL_SCANCODE_KP_9:
            ret += "Keypad 9";
            break;
        case SDL_SCANCODE_KP_A:
            ret += "Keypad A";
            break;
        case SDL_SCANCODE_KP_AMPERSAND:
            ret += "Keypad &";
            break;
        case SDL_SCANCODE_KP_AT:
            ret += "Keypad @";
            break;
        case SDL_SCANCODE_KP_B:
            ret += "Keypad B";
            break;
        case SDL_SCANCODE_KP_BACKSPACE:
            ret += "Keypad Backspace";
            break;
        case SDL_SCANCODE_KP_BINARY:
            ret += "Keypad Binary";
            break;
        case SDL_SCANCODE_KP_C:
            ret += "Keypad C";
            break;
        case SDL_SCANCODE_KP_CLEAR:
            ret += "Keypad Clear";
            break;
        case SDL_SCANCODE_KP_CLEARENTRY:
            ret += "Keypad Clearentry";
            break;
        case SDL_SCANCODE_KP_COLON:
            ret += "Keypad :";
            break;
        case SDL_SCANCODE_KP_COMMA:
            ret += "Keypad ,";
            break;
        case SDL_SCANCODE_KP_D:
            ret += "Keypad D";
            break;
        case SDL_SCANCODE_KP_DBLAMPERSAND:
            ret += "Keypad DBL &";
            break;
        case SDL_SCANCODE_KP_DBLVERTICALBAR:
            ret += "Keypad DBL |";
            break;
        case SDL_SCANCODE_KP_DECIMAL:
            ret += "Keypad Decimal";
            break;
        case SDL_SCANCODE_KP_DIVIDE:
            ret += "Keypad Divide";
            break;
        case SDL_SCANCODE_KP_E:
            ret += "Keypad E";
            break;
        case SDL_SCANCODE_KP_ENTER:
            ret += "Keypad Enter";
            break;
        case SDL_SCANCODE_KP_EQUALS:
            ret += "Keypad Equals";
            break;
        case SDL_SCANCODE_KP_EQUALSAS400:
            ret += "Keypad Equals As 400";
            break;
        case SDL_SCANCODE_KP_EXCLAM:
            ret += "Keypad !";
            break;
        case SDL_SCANCODE_KP_F:
            ret += "Keypad F";
            break;
        case SDL_SCANCODE_KP_GREATER:
            ret += "Keypad >";
            break;
        case SDL_SCANCODE_KP_HASH:
            ret += "Keypad Hash";
            break;
        case SDL_SCANCODE_KP_HEXADECIMAL:
            ret += "Keypad Hexadecimal";
            break;
        case SDL_SCANCODE_KP_LEFTBRACE:
            ret += "Keypad [";
            break;
        case SDL_SCANCODE_KP_LEFTPAREN:
            ret += "Keypad (";
            break;
        case SDL_SCANCODE_KP_LESS:
            ret += "Keypad <";
            break;
        case SDL_SCANCODE_KP_MEMADD:
            ret += "Keypad Mem Add";
            break;
        case SDL_SCANCODE_KP_MEMCLEAR:
            ret += "Keypad Mem Clear";
            break;
        case SDL_SCANCODE_KP_MEMDIVIDE:
            ret += "Keypad Mem Divide";
            break;
        case SDL_SCANCODE_KP_MEMMULTIPLY:
            ret += "Keypad Mem Multiply";
            break;
        case SDL_SCANCODE_KP_MEMRECALL:
            ret += "Keypad Mem Recall";
            break;
        case SDL_SCANCODE_KP_MEMSTORE:
            ret += "Keypad Mem Store";
            break;
        case SDL_SCANCODE_KP_MEMSUBTRACT:
            ret += "Keypad Mem Subtract";
            break;
        case SDL_SCANCODE_KP_MINUS:
            ret += "Keypad Minus";
            break;
        case SDL_SCANCODE_KP_MULTIPLY:
            ret += "Keypad Multiply";
            break;
        case SDL_SCANCODE_KP_OCTAL:
            ret += "Keypad Octal";
            break;
        case SDL_SCANCODE_KP_PERCENT:
            ret += "Keypad %";
            break;
        case SDL_SCANCODE_KP_PERIOD:
            ret += "Keypad .";
            break;
        case SDL_SCANCODE_KP_PLUS:
            ret += "Keypad Plus";
            break;
        case SDL_SCANCODE_KP_PLUSMINUS:
            ret += "Keypad Plus Minus";
            break;
        case SDL_SCANCODE_KP_POWER:
            ret += "Keypad Power";
            break;
        case SDL_SCANCODE_KP_RIGHTBRACE:
            ret += "Keypad ]";
            break;
        case SDL_SCANCODE_KP_RIGHTPAREN:
            ret += "Keypad )";
            break;
        case SDL_SCANCODE_KP_SPACE:
            ret += "Keypad Space";
            break;
        case SDL_SCANCODE_KP_TAB:
            ret += "Keypad Tab";
            break;
        case SDL_SCANCODE_KP_VERTICALBAR:
            ret += "Keypad |";
            break;
        case SDL_SCANCODE_KP_XOR:
            ret += "Keypad Xor";
            break;
        case SDL_SCANCODE_LALT:
            ret += "Left Alt";
            break;
        case SDL_SCANCODE_LCTRL:
            ret += "Left Ctrl";
            break;
        case SDL_SCANCODE_LEFT:
            ret += "Left";
            break;
        case SDL_SCANCODE_LEFTBRACKET:
            ret += '[';
            break;
        case SDL_SCANCODE_LGUI:
            ret += "Left GUI";
            break;
        case SDL_SCANCODE_LSHIFT:
            ret += "Left Shift";
            break;
        case SDL_SCANCODE_MAIL:
            ret += "Mail";
            break;
        case SDL_SCANCODE_MEDIASELECT:
            ret += "Media Select";
            break;
        case SDL_SCANCODE_MENU:
            ret += "Menu";
            break;
        case SDL_SCANCODE_MINUS:
            ret += '-';
            break;
        case SDL_SCANCODE_MODE:
            ret += "Mode lolwtf";
            break;
        case SDL_SCANCODE_NUMLOCKCLEAR:
            ret += "Numlock/Clear";
            break;
        case SDL_SCANCODE_OPER:
            ret += "Oper";
            break;
        case SDL_SCANCODE_OUT:
            ret += "Out";
            break;
        case SDL_SCANCODE_PAGEDOWN:
            ret += "Pagedown";
            break;
        case SDL_SCANCODE_PAGEUP:
            ret += "Pageup";
            break;
        case SDL_SCANCODE_PASTE:
            ret += "Paste";
            break;
        case SDL_SCANCODE_PERIOD:
            ret += '.';
            break;
        case SDL_SCANCODE_POWER:
            ret += "lol did u really hit the power key wtf";
            break;
        case SDL_SCANCODE_PRINTSCREEN:
            ret += "Printscreen";
            break;
        case SDL_SCANCODE_PRIOR:
            ret += "Prior";
            break;
        case SDL_SCANCODE_RALT:
            ret += "Right Alt";
            break;
        case SDL_SCANCODE_RCTRL:
            ret += "Right Ctrl";
            break;
        case SDL_SCANCODE_RETURN:
            ret += "Return";
            break;
        case SDL_SCANCODE_RETURN2:
            ret += "Also Return .-.";
            break;
        case SDL_SCANCODE_RGUI:
            ret += "Right GUI";
            break;
        case SDL_SCANCODE_RIGHT:
            ret += "Right";
            break;
        case SDL_SCANCODE_RIGHTBRACKET:
            ret += ']';
            break;
        case SDL_SCANCODE_RSHIFT:
            ret += "Right Shift";
            break;
        case SDL_SCANCODE_SCROLLLOCK:
            ret += "Sroll lock";
            break;
        case SDL_SCANCODE_SELECT:
            ret += "Select";
            break;
        case SDL_SCANCODE_SEMICOLON:
            ret += ';';
            break;
        case SDL_SCANCODE_SEPARATOR:
            ret += "Separator";
            break;
        case SDL_SCANCODE_SLASH:
            ret += '/';
            break;
        case SDL_SCANCODE_SLEEP:
            ret += "Sleeeeeep";
            break;
        case SDL_SCANCODE_SPACE:
            ret += "Spaaaace";
            break;
        case SDL_SCANCODE_STOP:
            ret += "Stop";
            break;
        case SDL_SCANCODE_SYSREQ:
            ret += "What even is SysReq";
            break;
        case SDL_SCANCODE_TAB:
            ret += "Tab";
            break;
        case SDL_SCANCODE_THOUSANDSSEPARATOR:
            ret += "Thousands Separator";
            break;
        case SDL_SCANCODE_UNDO:
            ret += "Undo";
            break;
        case SDL_SCANCODE_UP:
            ret += "Up";   /// sad movie
            break;
        case SDL_SCANCODE_VOLUMEDOWN:
            ret += "Volume Down";
            break;
        case SDL_SCANCODE_VOLUMEUP:
            ret += "Volume Up";
            break;
        case SDL_SCANCODE_WWW:
            ret += "Internet";
            break;
        default:
        case SDL_SCANCODE_UNKNOWN:
            ret += "You've hit a key which isn't one of the fucking keys above congrats";
            break;
        }
        
        return ret;
    }
    
    const SUCCESS EventLogger::mouseEnter(const Uint32 window)
    {
        out<<"Mouse focused on window "<<window<<endl;
        return SUCCEEDED;
    }
    
    const SUCCESS EventLogger::mouseLeave(const Uint32 window)
    {
        out<<"Mouse focus left window "<<window<<endl;
        return SUCCEEDED;
    }
    
    const SUCCESS EventLogger::keyboardFocusGain(const Uint32 window)
    {
        out<<"Keyboard focus on window "<<window<<endl;
        return SUCCEEDED;
    }
    
    const SUCCESS EventLogger::keyboardFocusLost(const Uint32 window)
    {
        out<<"Keyboard focus left window "<<window<<endl;
        return SUCCEEDED;
    }
    
    const SUCCESS EventLogger::minimized(const Uint32 window)
    {
        out<<"Window "<<window<<" was minimized"<<endl;
        return SUCCEEDED;
    }
    
    const SUCCESS EventLogger::restored(const Uint32 window)
    {
        out<<"Window "<<window<<" was restored"<<endl;
        return SUCCEEDED;
    }
    
    const SUCCESS EventLogger::maximized(const Uint32 window)
    {
        out<<"Window "<<window<<" was maximized"<<endl;
        return SUCCEEDED;
    }
    
    const SUCCESS EventLogger::resized(const Uint32 window, const Dimensions<int> &size)
    {
        out<<"Window "<<window<<" resized to "<<size<<endl;
        return SUCCEEDED;
    }
    
    const SUCCESS EventLogger::moved(const Uint32 window, const Point<int> &pos)
    {
        out<<"Window "<<window<<" moved to "<<pos<<endl;
        return SUCCEEDED;
    }
    
    const SUCCESS EventLogger::exposed(const Uint32 window)
    {
        out<<"Window "<<window<<" exposed"<<endl;
        return SUCCEEDED;
    }
    
    const SUCCESS EventLogger::shown(const Uint32 window)
    {
        out<<"Window "<<window<<" shown"<<endl;
        return SUCCEEDED;
    }
    
    const SUCCESS EventLogger::hidden(const Uint32 window)
    {
        out<<"Window "<<window<<" hidden"<<endl;
        return SUCCEEDED;
    }
    
    const SUCCESS EventLogger::windowExited(const Uint32 window)
    {
        out<<"Window "<<window<<" exiting"<<endl;
        return SUCCEEDED;
    }
    
    const SUCCESS EventLogger::keyHeld(const Uint32 window, const SDL_Keysym &key)
    {
        out<<toString(key)<<" key held at window "<<window<<endl;
        return SUCCEEDED;
    }
    
    const SUCCESS EventLogger::keyPressed(const Uint32 window, const SDL_Keysym &key)
    {
        out<<toString(key)<<" key pressed at window "<<window<<endl;
        return SUCCEEDED;
    }
    
    const SUCCESS EventLogger::keyReleased(const Uint32 window, const SDL_Keysym &key)
    {
        out<<toString(key)<<" key released at window "<<window<<endl;
        return SUCCEEDED;
    }
    
    const SUCCESS EventLogger::textInput(const Uint32 window, const char * const text)
    {
        out<<"Text input: "<<text<<endl;
        return SUCCEEDED;
    }
    
    const SUCCESS EventLogger::textEdit(const Uint32 window, const char * const text, const int start, const int length)
    {
        out<<"Text edit of "<<text<<" at char "<<start<<" for "<<length<<" characters"<<endl;
        return SUCCEEDED;
    }
    
    const SUCCESS EventLogger::mouseMove(const Uint32 window, const Uint32 mouse, const Delta<Point<int> > &movement,
                                         const bitset<N_MOUSE_BUTTONS> &buttons)
    {
        out<<"Mouse "<<mouse<<" moved to "<<movement.get()<<" at rate "<<movement<<" in window "<<window<<"with button config: "<<buttons<<endl;
        return SUCCEEDED;
    }
    
    const SUCCESS EventLogger::mouseButtonPressed(const Uint32 window, const Uint32 mouse, 
                                                  const Uint8 button, const Uint8 clicks, const Point<int> &mPos)
    {
        out<<"Mouse "<<mouse<<", button "<<int(button)<<", pressed ";
        out<<int(clicks)<<(clicks == 1? " time, at ":" times, at ")<<mPos<<" in window "<<window<<endl;
        return SUCCEEDED;
    }
    
    const SUCCESS EventLogger::mouseButtonReleased(const Uint32 window, const Uint32 mouse, 
                                                  const Uint8 button, const Uint8 clicks, const Point<int> &mPos)
    {
        out<<"Mouse "<<mouse<<", button "<<int(button)<<", released ";
        out<<int(clicks)<<(clicks == 1? " time, at ":" times, at ")<<mPos<<" in window "<<window<<endl;
        return SUCCEEDED;
    }
    
    const SUCCESS EventLogger::mouseWheel(const Uint32 window, const Uint32 mouse, const Point<int> &scroll)
    {
        out<<"Mouse "<<mouse<<" wheel changed by "<<scroll<<" in window "<<window<<endl;
        return SUCCEEDED;
    }
    
    const SUCCESS EventLogger::joyAxis(const SDL_JoystickID stick, const Uint8 axis, const Sint16 value)
    {
        out<<"Joystick "<<stick<<", axis "<<int(axis)<<", in position "<<value<<endl;
        return SUCCEEDED;
    }
    
    const SUCCESS EventLogger::joyButtonPressed(const SDL_JoystickID stick, const Uint8 button)
    {
        out<<"Joystick "<<stick<<", button "<<int(button)<<" pressed"<<endl;
        return SUCCEEDED;
    }
    
    const SUCCESS EventLogger::joyButtonReleased(const SDL_JoystickID stick, const Uint8 button)
    {
        out<<"Joystick "<<stick<<", button "<<int(button)<<" released"<<endl;
        return SUCCEEDED;
    }
    
    const SUCCESS EventLogger::joyHatChange(const SDL_JoystickID stick, const Uint8 hat, const Uint8 position)
    {
        out<<"Joystick "<<stick<<", hat "<<int(hat)<<" in position "<<int(position)<<endl;
        return SUCCEEDED;
    }
    
    const SUCCESS EventLogger::joyBallMove(const SDL_JoystickID stick, const Uint8 ball, const Point<Sint16> &rel)
    {
        out<<"Joystick "<<stick<<", ball "<<int(ball)<<" moved by "<<rel<<endl;
        return SUCCEEDED;
    }
    
    const SUCCESS EventLogger::joyAdded(const Sint32 device)
    {
        out<<"Device "<<device<<" added as joystick"<<endl;
        return SUCCEEDED;
    }
    
    const SUCCESS EventLogger::joyRemoved(const Sint32 id)
    {
        out<<"Joystick "<<id<<" removed from joysticks"<<endl;
        return SUCCEEDED;
    }
    
    const SUCCESS EventLogger::droppedFile(const char * const file)
    {
        out<<"File "<<file<<" dropped to application"<<endl;
        return SUCCEEDED;
    }
    
    const SUCCESS EventLogger::unhandledSystemEvent(SDL_SysWMmsg * const msg)
    {
        out<<"unhandled system event u can figure this one out loooooool"<<endl;
        return SUCCEEDED;
    }
    
    const SUCCESS EventLogger::userEvent(const Uint32 window, const int code, void * const data1, void * const data2)
    {
        out<<"User Event in window "<<window<<" with code "<<code<<" with some data whatever teh heck"<<endl;
        return SUCCEEDED;
    }
}