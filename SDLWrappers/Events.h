#ifndef _EVENT_H_
#define _EVENT_H_

#include <bitset>

#include "Declarations.h"
#include "App.h"
#include "Window.h"

namespace jer {
    using std::bitset;
    
    enum {N_MOUSE_BUTTONS=5};
    
class Events {
/** Organizes Events by their type and other properties.
  * There is a function for every type and some properties of each type.
  * If a certain classification of a type of an Event has many distinct properties, it is passed
  * as an argument for that classification's function.
  * Events is a pure virtual class, and shouldn't even be inherited.
  * As far as a client is concerned, they only need the function prototypes to overload
  * in some child class of GameLoop.
  */
private:
    static Events *eventListener;
    static Uint32 timestamp;
    
public:
    static void SetListener(Events * const el) {eventListener = el;};
    static const Events * const GetListener() {return eventListener;};
    static const SUCCESS PollEvents();
    static const Uint32 GetPreviousEventTimestamp() {return timestamp;};

public:
  Events();
  virtual ~Events();

  /// Classifies the SDL_Event based on type and other properties and calls the respective function.
  virtual const SUCCESS handleEvent(const SDL_Event * const Event);

  /// Called when the window gains mouse focus (when mouse clicks on window)
  virtual const SUCCESS mouseEnter(const Uint32 window) {};

  /// Called when the window loses mouse focus (when mouse clicks outside of window)
  virtual const SUCCESS mouseLeave(const Uint32 window) {};
  
  /// Called when the SDL window is minimized
  virtual const SUCCESS minimized(const Uint32 window) {};

  /// Called when the SDL window is restored
  virtual const SUCCESS restored(const Uint32 window) {};
  
  /// Called when the SDL window is resized.
  virtual const SUCCESS resized(const Uint32 window, const Dimensions<int> &size) {};
  
  /// Called when the SDL window is moved. 
  virtual const SUCCESS moved(const Uint32 window, const Point<int> &pos) {};

    /// Called when the SDL window is modified outside of the application, usually by the windows manager and needs to be redrawn.
  virtual const SUCCESS exposed(const Uint32 window) {};
  
  /// Called when the SDL window is X-ed (won't automatically close). Pure virtaul, Must be overloaded.
  virtual const SUCCESS windowExited(const Uint32 window)=0;
  
  /// Called when the last SDL Window is exited.
  virtual const SUCCESS appExited();

  /** Called if a key has remained held down. (SDL Key Repeat must be enabled)
    * @window: the id of the window with keyboard focus
    * @key: a struct containing the keycode, scancode, and modifiers of the key event.
    */
  virtual const SUCCESS keyHeld(const Uint32 window, const SDL_Keysym key) {};

  /// Called when a key on the keyboard goes from up to down. See Events::keyHeld for parameter synopsis.
  virtual const SUCCESS keyPressed(const Uint32 window, const SDL_Keysym key) {};
  
  /// Called when a key on the keyboard goes from down to up. See Events::keyHeld for parameter synopsis.
  virtual const SUCCESS keyReleased(const Uint32 window, const SDL_Keysym key) {};

  /** Called when the mouse moves.
   * @movement: a Delta containing the current position and relative movement of the mouse
   * @*down: if true, that
   */
  virtual const SUCCESS mouseMove(const Uint32 window, const Uint32 mouse, const Delta<Point<int> > &movement, 
                                  const bitset<N_MOUSE_BUTTONS> &buttons) {};

  /** Called when a mouse button is currently down. Mouse position at (mX, mY).
    * button represents which button is down, either SDL_BUTTON_LEFT, SDL_BUTTON_RIGHT, or SDL_BUTTON_MIDDLE.
    */
  virtual const SUCCESS mouseButtonDown(const Uint8 button, const Point<int> &mPos) {};

  /// Called when a mouse button goes from up to down. Mouse position at (mX, mY). See Events::mouseButtonDown.
  virtual const SUCCESS mouseButtonPressed(const Uint8 button, const Point<int> &mPos) {};

  /// Called when a mouse button goes is currently up. Mouse position at (mX, mY). See Events::mouseButtonDown.
  virtual const SUCCESS mouseButtonUp(const Uint8 button, const Point<int> &mPos) {};

  /// Called when a mouse button goes from down to up. Mouse position at (mX, mY). See Events::mouseButtonUp.
  virtual const SUCCESS mouseButtonReleased(const Uint8 button, const Point<int> &mPos) {};

  /** Called when the joystick reports a value on one of the axes. 
    * which = "which joystick"
    * axis = "which axis"
    * value = "magnitude of which in the axis direction"
    */
  virtual const SUCCESS joyAxis(const Uint8 which, const Uint8 axis, const Sint16 value) {};

  /// Called when a joystck button is currently in the down position. which = "which joystick." button = "which button."
  virtual const SUCCESS joyButtonDown(const Uint8 which, const Uint8 button) {};

  /// Called when a joystick button goes from up to down. see GameControl::Events::joyButtonDown
  virtual const SUCCESS joyButtonPressed(const Uint8 which, const Uint8 button) {};

  /// Called when a joystick button is currently in the up position. see GameControl::Events::joyButtonDown
  virtual const SUCCESS joyButtonUp(const Uint8 which, const Uint8 button) {};

  /// Called when a joystick button goes from down to up. see GameControl::Events::joyButtonDown
  virtual const SUCCESS joyButtonReleased(const Uint8 which, const Uint8 button) {};

  /** Called when the joystick hat position changes. hat = "hat id". 
    * value: SDL_HAT_CENTERED, SDL_HAT_UP, SDL_HAT_RIGHT, SDL_HAT_DOWN, SDL_HAT_LEFT, 
    * SDL_HAT_RIGHTUP, SDL_HAT_RIGHTDOWN, SDL_HAT_LEFTDOWN, SDL_HAT_LEFTUP
    */
  virtual const SUCCESS joyHatChange(const Uint8 which, const Uint8 hat, const Uint8 value) {};

  /// Called when the joystick ball moves. (joystick-ception). ball = "ball id". Relative change (xRel, yRel).
  virtual const SUCCESS joyBallMove(const Uint8 which, const Uint8 ball, const Point<Sint16> &rel) {};

  /// Called when an unhandled event by the systme's windows manager is sent.
  virtual const SUCCESS unhandledSystemEvent(SDL_SysWMmsg * const msg) {};

  /** Called when SDL_UserEvent is handled. This event is thrown by the user and is very generic.
    * consists of a code (2^sizeof(int) different allowed values),
    * and two generic data values of type void *, whose data type should be known by the user for their
    * respective code and cast to that type.
    */
  virtual const SUCCESS userEvent(const int code, void * const data1, void * const data2) {};

};

}


#endif /*_EVENT_H_*/
