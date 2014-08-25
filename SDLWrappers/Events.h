#ifndef _EVENT_H_
#define _EVENT_H_

#include <bitset>
#include <memory>

#include "Declarations.h"
#include "App.h"
#include "Window.h"
#include "ControlInterfaces/Loopable.h"

namespace jer {
    using std::bitset;
    using std::shared_ptr;
    
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
    
protected:
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
  
  /// Called when the SDL window gains keyboard focus
  virtual const SUCCESS keyboardFocusGain(const Uint32 window) {};
  
  /// Called when the SDL window loses keyboard focus
  virtual const SUCCESS keyboardFocusLost(const Uint32 window) {};
  
  /// Called when the SDL window is minimized
  virtual const SUCCESS minimized(const Uint32 window) {};

  /// Called when the SDL window is restored
  virtual const SUCCESS restored(const Uint32 window) {};
  
  /// Called when the SDL window is maximized
  virtual const SUCCESS maximized(const Uint32 window) {};
  
  /// Called when the SDL window is resized.
  virtual const SUCCESS resized(const Uint32 window, const Dimensions<int> &size) {};
  
  /// Called when the SDL window is moved. 
  virtual const SUCCESS moved(const Uint32 window, const Point<int> &pos) {};

    /// Called when the SDL window is modified outside of the application, usually by the windows manager and needs to be redrawn.
  virtual const SUCCESS exposed(const Uint32 window) {};
  
  /// Called when the SDL Window is shown or something
  virtual const SUCCESS shown(const Uint32 window) {};
  
  /// Called when the SDL Window is hidden behind other windows
  virtual const SUCCESS hidden(const Uint32 window) {};
  
  /// Called when the SDL window is X-ed (won't automatically close). Pure virtaul, Must be overloaded.
  virtual const SUCCESS windowExited(const Uint32 window)=0;
  
  /// Called when the last SDL Window is exited.
  virtual const SUCCESS appExited() {App::GetApp().stop();};

  /** Called if a key has remained held down. (SDL Key Repeat must be enabled)
    * @window: the id of the window with keyboard focus
    * @key: a struct containing the keycode, scancode, and modifiers of the key event.
    */
  virtual const SUCCESS keyHeld(const Uint32 window, const SDL_Keysym &key) {};

  /// Called when a key on the keyboard goes from up to down. See Events::keyHeld for parameter synopsis.
  virtual const SUCCESS keyPressed(const Uint32 window, const SDL_Keysym &key) {};
  
  /// Called when a key on the keyboard goes from down to up. See Events::keyHeld for parameter synopsis.
  virtual const SUCCESS keyReleased(const Uint32 window, const SDL_Keysym &key) {};
  
  /// Called when the OS sends text input
  virtual const SUCCESS textInput(const Uint32 window, const char * const text) {};
  
  /// Called when the OS sends text editing
  virtual const SUCCESS textEdit(const Uint32 window, const char * const text, const int start, const int length) {};

  /** Called when the mouse moves.
   * @movement: a Delta containing the current position and relative movement of the mouse
   * @buttons: a bitmask of the current mouse buttons
   */
  virtual const SUCCESS mouseMove(const Uint32 window, const Uint32 mouse, const Delta<Point<int> > &movement, 
                                  const bitset<N_MOUSE_BUTTONS> &buttons) {};

  /** Called when a mouse button is pressed.
    * @window: id of the window
    * @mouse: id of the mouse
    * @button: id of the button
    * @clicks: 1 for single click, 2 for double click, etc.
    * @mPos: position of mouse relative to the window
    */
  virtual const SUCCESS mouseButtonPressed(const Uint32 window, const Uint32 mouse, 
                                           const Uint8 button, const Uint8 clicks, const Point<int> &mPos) {};

  /// Called when a mouse button goes from down to up. Mouse position at (mX, mY). See Events::mouseButtonUp.
  virtual const SUCCESS mouseButtonReleased(const Uint32 window, const Uint32 mouse, 
                                            const Uint8 button, const Uint8 clicks, const Point<int> &mPos) {};
  
  /// Called when the mouse wheel scrolls at the relative differential of scroll
  virtual const SUCCESS mouseWheel(const Uint32 window, const Uint32 mouse, const Point<int> &scroll) {};
  
  /// Called when a joystick axis changes. Value represents the current position along the axis on stick.axis
  virtual const SUCCESS joyAxis(const SDL_JoystickID stick, const Uint8 axis, const Sint16 value) {};

  /// Called when joystick button which.button is pressed.
  virtual const SUCCESS joyButtonPressed(const SDL_JoystickID stick, const Uint8 button) {};

  /// Called when joystick button stick.button is released
  virtual const SUCCESS joyButtonReleased(const SDL_JoystickID stick, const Uint8 button) {};

  /** Called when the joystick hat position changes. hat = "hat id". 
    * value: SDL_HAT_CENTERED, SDL_HAT_UP, SDL_HAT_RIGHT, SDL_HAT_DOWN, SDL_HAT_LEFT, 
    * SDL_HAT_RIGHTUP, SDL_HAT_RIGHTDOWN, SDL_HAT_LEFTDOWN, SDL_HAT_LEFTUP
    */
  virtual const SUCCESS joyHatChange(const SDL_JoystickID stick, const Uint8 hat, const Uint8 position) {};

  /// Called when the joystick ball moves. (joystick-ception). ball = "ball id". Relative change rel.
  virtual const SUCCESS joyBallMove(const SDL_JoystickID stick, const Uint8 ball, const Point<Sint16> &rel) {};
  
  /// Called when a joystick device is added.
  virtual const SUCCESS joyAdded(const Sint32 device) {};
  
  /// Called when a joystick device is removed
  virtual const SUCCESS joyRemoved(const Sint32 id) {};
  
  /// Called when a file is dragged and dropped into an SDL Window
  virtual const SUCCESS droppedFile(const char * const file) {};
  
  /// Called when an unhandled event by the systme's windows manager is sent.
  virtual const SUCCESS unhandledSystemEvent(SDL_SysWMmsg * const msg) {};

  /** Called when SDL_UserEvent is handled. This event is thrown by the user and is very generic.
    * consists of a code (2^sizeof(int) different allowed values),
    * and two generic data values of type void *, whose data type should be known by the user for their
    * respective code and cast to that type.
    */
  virtual const SUCCESS userEvent(const Uint32 window, const int code, void * const data1, void * const data2) {};

};

class EventLoop: public Loopable
{
private:
    static shared_ptr<EventLoop> instance;
    
public:
    static EventLoop& GetInstance() {return *instance;};
    static const shared_ptr<EventLoop> GetReference() {return instance;};
    
private:
    EventLoop() {};
    EventLoop(const EventLoop& other) {};
    
public:
    virtual ~EventLoop() {};
    
public:
    const SUCCESS loop() override
    {
        return Events::PollEvents();
    };
};

}


#endif /*_EVENT_H_*/
