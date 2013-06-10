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
  Events();
  virtual ~Events();

  /// Classifies the SDL_Event based on type and other properties and calls the respective function.
  virtual const EVENT_RESULT handleEvent(SDL_Event * const Event);

  /// Called when the window gains input focus (when keyboard or other input is sent to the SDL Window)
  virtual const EVENT_RESULT inputFocus();

  /// Called when the window loses input focus (when keyboard or other is no longer sent to the SDL Window)
  virtual const EVENT_RESULT inputBlur();

  /// Called when the window gains mouse focus (when mouse clicks on window)
  virtual const EVENT_RESULT mouseFocus();

  /// Called when the window loses mouse focus (when mouse clicks outside of window)
  virtual const EVENT_RESULT mouseBlur();

  /** Called when a key on the keyboard is reported to be in the down state, 
    * which if held down happens as often as is specified in SDL_EnableKeyRepeat(int delay, int interval) by interval
    *
    * sym is the SDL Key identifier such as SDL_KEYDOWN. mod is the current key mods, such as CTRL, ALT, etc.
    * unicode is the translated character input of the key press. If SDL_EnableUnicode() was called, unicode should correspond
    * to a unicode character. (if the upper 9 bits are 0, unicode is an ASCII character).
    */
  virtual const EVENT_RESULT keyDown(const SDLKey sym, const SDLMod mod, const Uint16 unicode);

  /// Called when a key on the keyboard goes from up to down. See GameControl::Events::keyDown for parameter synopsis.
  virtual const EVENT_RESULT keyPressed(const SDLKey sym, const SDLMod mod, const Uint16 unicode);

  /// Called when a key on the keyboard is reported to be in the up state, see GameControl::Events::keyDown for more info
  virtual const EVENT_RESULT keyUp(const SDLKey sym, const SDLMod mod, const Uint16 unicode);
  
  /// Called when a key on the keyboard goes from down to up. See GameControl::Event::keyDown for parameter synopsis.
  virtual const EVENT_RESULT keyReleased(const SDLKey sym, const SDLMod mod, const Uint16 unicode);

  /** Called when the mouse moves. Current Mouse position (mX pixels, mY pixels). Relative change in position (relX pixels, relY pixels).
    * Left button is down -> lDown = true. Right button is down -> rDown = true. Middle button is down -> mDown = true.
    */
  virtual const EVENT_RESULT mouseMove(const int mX, const int mY, const int relX, const int relY, 
                                      const bool lDown, const bool rDown, const bool mDown);

  /** Called when a mouse button is currently down. Mouse position at (mX, mY).
    * button represents which button is down, either SDL_BUTTON_LEFT, SDL_BUTTON_RIGHT, or SDL_BUTTON_MIDDLE
    */
  virtual const EVENT_RESULT mouseButtonDown(const Uint8 button, const int mX, const int mY);


  
};

}


#endif /*_EVENT_H_*/