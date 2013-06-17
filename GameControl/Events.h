#ifndef _EVENT_H_
#define _EVENT_H_

#include "GameControl.h"


namespace GameControl {


/// All event functions return success or failure. Up to client to determine more results, or what to do with them.
enum {EVENT_SUCCESS, EVENT_FAILURE};
typedef Uint8 EVENT_RESULT;

class Events {
/** Organizes Events by their type and other properties.
  * There is a function for every type and some properties of each type.
  * If a certain classification of a type of an Event has many distinct properties, it is passed
  * as an argument for that classification's function.
  * Events is a pure virtual class, and shouldn't even be inherited.
  * As far as a client is concerned, they only need the function prototypes to overload
  * in some child class of GameLoop.
  */
public:
  static bitset<NUM_KEYS> keys; ///< keeps track of every current key state (1 pressed, 0 not pressed)
  static bitset<NUM_MOUSE_BUTTON> mouseButtons; ///< keeps track of every current mouse button state (1 pressed, 0 not pressed)
  static vector<bool> joystickButtons; ///< keeps track of every joy button
  Events();
  virtual ~Events();

  /// Classifies the SDL_Event based on type and other properties and calls the respective function.
  virtual const EVENT_RESULT handleEvent(SDL_Event * const Event);

  /// Called when the window gains input focus (when keyboard or other input is sent to the SDL Window)
  virtual const EVENT_RESULT inputFocus() {};

  /// Called when the window loses input focus (when keyboard or other is no longer sent to the SDL Window)
  virtual const EVENT_RESULT inputBlur() {};

  /// Called when the window gains mouse focus (when mouse clicks on window)
  virtual const EVENT_RESULT mouseFocus() {};

  /// Called when the window loses mouse focus (when mouse clicks outside of window)
  virtual const EVENT_RESULT mouseBlur() {};
  
  /// Called when the SDL window is minimized
  virtual const EVENT_RESULT minimized() {};

  /// Called when the SDL window is restored
  virtual const EVENT_RESULT restored() {};
  
  /// Called when the SDL window is resized. W is new width. H is new height
  virtual const EVENT_RESULT resized(const int W, const int H) {};

  /// TODO: figure out what expose is.
  /// Called when the SDL window is modified outside of the application, usually by the windows manager and needs to be redrawn.
  virtual const EVENT_RESULT exposed() {};
  
  /// Called when the SDL window is X-ed (won't automatically close). Pure virtaul, Must be overloaded.
  virtual const EVENT_RESULT exited()=0;

  /** Called when a key on the keyboard is reported to be in the down state, 
    * which if held down happens as often as is specified in SDL_EnableKeyRepeat(int delay, int interval) by interval
    *
    * sym is the SDL Key identifier such as SDL_KEYDOWN. mod is the current key mods, such as CTRL, ALT, etc.
    * unicode is the translated character input of the key press. If SDL_EnableUnicode() was called, unicode should correspond
    * to a unicode character. (if the upper 9 bits are 0, unicode is an ASCII character).
    */
  virtual const EVENT_RESULT keyDown(const SDLKey sym, const SDLMod mod, const Uint16 unicode) {};

  /// Called when a key on the keyboard goes from up to down. See GameControl::Events::keyDown for parameter synopsis.
  virtual const EVENT_RESULT keyPressed(const SDLKey sym, const SDLMod mod, const Uint16 unicode) {};

  /// Called when a key on the keyboard is reported to be in the up state, see GameControl::Events::keyDown for more info.
  virtual const EVENT_RESULT keyUp(const SDLKey sym, const SDLMod mod, const Uint16 unicode) {};
  
  /// Called when a key on the keyboard goes from down to up. See GameControl::Event::keyDown for parameter synopsis.
  virtual const EVENT_RESULT keyReleased(const SDLKey sym, const SDLMod mod, const Uint16 unicode) {};

  /** Called when the mouse moves. Current Mouse position (mX pixels, mY pixels). Relative change in position (relX pixels, relY pixels).
    * Left button is down -> lDown = true. Right button is down -> rDown = true. Middle button is down -> mDown = true.
    */
  virtual const EVENT_RESULT mouseMove(const int mX, const int mY, const int relX, const int relY, 
                                      const bool lDown, const bool rDown, const bool mDown) {};

  /** Called when a mouse button is currently down. Mouse position at (mX, mY).
    * button represents which button is down, either SDL_BUTTON_LEFT, SDL_BUTTON_RIGHT, or SDL_BUTTON_MIDDLE.
    */
  virtual const EVENT_RESULT mouseButtonDown(const Uint8 button, const int mX, const int mY) {};

  /// Called when a mouse button goes from up to down. Mouse position at (mX, mY). See GameControl::Events::mouseButtonDown.
  virtual const EVENT_RESULT mouseButtonPressed(const Uint8 button, const int mX, const int mY) {};

  /// Called when a mouse button goes is currently up. Mouse position at (mX, mY). See GameControl::Events::mouseButtonDown.
  virtual const EVENT_RESULT mouseButtonUp(const Uint8 button, const int mX, const int mY) {};

  /// Called when a mouse button goes from down to up. Mouse position at (mX, mY). See GameControl::Events::mouseButtonUp.
  virtual const EVENT_RESULT mouseButtonReleased(const Uint8 button, const int mX, const int mY) {};

  /** Called when the joystick reports a value on one of the axes. 
    * which = "which joystick"
    * axis = "which axis"
    * value = "magnitude of which in the axis direction"
    */
  virtual const EVENT_RESULT joyAxis(const Uint8 which, const Uint8 axis, const Sint16 value) {};

  /// Called when a joystck button is currently in the down position. which = "which joystick." button = "which button."
  virtual const EVENT_RESULT joyButtonDown(const Uint8 which, const Uint8 button) {};

  /// Called when a joystick button goes from up to down. see GameControl::Events::joyButtonDown
  virtual const EVENT_RESULT joyButtonPressed(const Uint8 which, const Uint8 button) {};

  /// Called when a joystick button is currently in the up position. see GameControl::Events::joyButtonDown
  virtual const EVENT_RESULT joyButtonUp(const Uint8 which, const Uint8 button) {};

  /// Called when a joystick button goes from down to up. see GameControl::Events::joyButtonDown
  virtual const EVENT_RESULT joyButtonReleased(const Uint8 which, const Uint8 button) {};

  /** Called when the joystick hat position changes. hat = "hat id". 
    * value: SDL_HAT_CENTERED, SDL_HAT_UP, SDL_HAT_RIGHT, SDL_HAT_DOWN, SDL_HAT_LEFT, 
    * SDL_HAT_RIGHTUP, SDL_HAT_RIGHTDOWN, SDL_HAT_LEFTDOWN, SDL_HAT_LEFTUP
    */
  virtual const EVENT_RESULT joyHatChange(const Uint8 which, const Uint8 hat, const Uint8 value) {};

  /// Called when the joystick ball moves. (joystick-ception). ball = "ball id". Relative change (xRel, yRel).
  virtual const EVENT_RESULT joyBallMove(const Uint8 which, const Uint8 ball, const Sint16 xRel, const Sint16 yRel) {};

  /// Called when an unhandled event by the systme's windows manager is sent.
  virtual const EVENT_RESULT unhandledSystemEvent(SDL_SysWMmsg * const msg) {};

  /** Called when SDL_UserEvent is handled. This event is thrown by the user and is very generic.
    * consists of a code (2^sizeof(int) different allowed values),
    * and two generic data values of type void *, whose data type should be known by the user for their
    * respective code and cast to that type.
    */
  virtual const EVENT_RESULT userEvent(const int code, void * const data1, void * const data2) {};

};

}


#endif /*_EVENT_H_*/
