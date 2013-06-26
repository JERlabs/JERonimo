#include "TestEvents.h"

namespace GameControl {
TestEvents::TestEvents(DataManager * const dataM, GameLoop * const parent):
GameLoop(dataM, parent) {}

TestEvents::TestEvents(DataManager &dataM, GameLoop &parent): GameLoop(dataM, parent) {}

int const TestEvents::init() {
  cout<<"Starting Event printer"<<endl;
  Running = true;
  DataM->init();
  return 0;
}

int const TestEvents::loop() {
  static int ticks = 0;
  if(SDL_GetTicks() > ticks + 1000) {
    ticks = SDL_GetTicks();
    cout<<"------ t = "<<((int)SDL_GetTicks()/1000)<<" seconds ---------"<<endl;
  }

  return 0;
}

int const TestEvents::render() const  {
  return 0;
}

int const TestEvents::cleanup() {
  return 0;
}

const EVENT_RESULT TestEvents::inputFocus() {
  cout<<"The Game Window has gained control of input events"<<endl;
  return EVENT_SUCCESS;
}

const EVENT_RESULT TestEvents::inputBlur() {
  cout<<"The Game Window has lost input"<<endl;
  return EVENT_SUCCESS;
}

const EVENT_RESULT TestEvents::mouseFocus() {
  cout<<"The Game Window has gained control of mouse events"<<endl;
  return EVENT_SUCCESS;
}

const EVENT_RESULT TestEvents::mouseBlur() {
  cout<<"The Game Window has lost control of mouse events"<<endl;
  return EVENT_SUCCESS;
}

const EVENT_RESULT TestEvents::minimized() {
  cout<<"The Game Window has been minimized"<<endl;
  return EVENT_SUCCESS;
}

const EVENT_RESULT TestEvents::restored() {
  cout<<"The Game Window has been restored"<<endl;
  return EVENT_SUCCESS;
}

const EVENT_RESULT TestEvents::resized(const int W, const int H) {
  cout<<"Screen has been resized to have a width of "<<W<<" and a height of "<<H<<endl;
  return EVENT_SUCCESS;
}

const EVENT_RESULT TestEvents::exposed() {
  cout<<"Screen has been exposed (whatever the hell that means)"<<endl;
  return EVENT_SUCCESS;
}

const EVENT_RESULT TestEvents::exited() {
  cout<<"Game Window has been Ex-ed out"<<endl<<"exiting..."<<endl;
  Running = DataM->Running = false;
  return EVENT_SUCCESS;
}

string TestEvents::printKeys(const SDLKey sym, const SDLMod mod, const Uint16 unicode) {
  string rtrn;
  if(mod & KMOD_NUM) rtrn += "NumLock is on,\n";
  if(mod & KMOD_CAPS) rtrn += "Caps Lock is on,\n";
  if(mod & KMOD_LCTRL) rtrn += "Left ctrl is pressed,\n";
  if(mod & KMOD_RCTRL) rtrn += "Right ctrl is pressed,\n";
  if(mod & KMOD_LSHIFT) rtrn += "Left shift is pressed,\n";
  if(mod & KMOD_RSHIFT) rtrn += "Right shift is pressed,\n";
  if(mod & KMOD_LALT) rtrn += "Left Alt is pressed,\n";
  if(mod & KMOD_RALT) rtrn += "Right Alt is pressed,\n";
  
  switch(sym)
  {
  case SDLK_BACKSPACE:
    rtrn += "Backspace ";
    break;
  case SDLK_TAB:
    rtrn += "Tab ";
    break;
  case SDLK_CLEAR:
    rtrn += "Clear ";
    break;
  case SDLK_RETURN:
    rtrn += "Return ";
    break;
  case SDLK_PAUSE:
    rtrn += "Pause ";
    break;
  case SDLK_ESCAPE:
    rtrn += "Escape ";
    break;
  case SDLK_SPACE:
    rtrn += "Space ";
    break;
  case SDLK_UP:
    rtrn += "Up ";
    break;
  case SDLK_DOWN:
    rtrn += "Down ";
    break;
  case SDLK_RIGHT:
    rtrn += "Right ";
    break;
  case SDLK_LEFT:
    rtrn += "Left ";
    break;
  case SDLK_INSERT:
    rtrn += "Insert ";
    break;
  case SDLK_HOME:
    rtrn += "Home ";
    break;
  case SDLK_END:
    rtrn += "End ";
    break;
  case SDLK_PAGEUP:
    rtrn += "PageUp ";
    break;
  case SDLK_PAGEDOWN:
    rtrn += "PageDown ";
    break;
  case SDLK_F1:
    rtrn += "F1 ";
    break;
  case SDLK_F2:
    rtrn += "F2 ";
    break;
  case SDLK_F3:
    rtrn += "F3 ";
    break;
  case SDLK_F4:
    rtrn += "F4 ";
    break;
  case SDLK_F5:
    rtrn += "F5 ";
    break;
  case SDLK_F6:
    rtrn += "F6 ";
    break;
  case SDLK_F7:
    rtrn += "F7 ";
    break;
  case SDLK_F8:
    rtrn += "F8 ";
    break;
  case SDLK_F9:
    rtrn += "F9 ";
    break;
  case SDLK_F10:
    rtrn += "F10 ";
    break;
  case SDLK_F11:
    rtrn += "F11 ";
    break;
  case SDLK_F12:
    rtrn += "F12 ";
    break;
  case SDLK_F13:
    rtrn += "F13 ";
    break;
  case SDLK_F14:
    rtrn += "F14 ";
    break;
  case SDLK_F15:
    rtrn += "F15 ";
    break;
  case SDLK_NUMLOCK:
    rtrn += "NumLock ";
    break;
  case SDLK_CAPSLOCK:
    rtrn += "CapsLock ";
    break;
  case SDLK_SCROLLOCK:
    rtrn += "ScollLock ";
    break;
  case SDLK_RSHIFT:
    rtrn += "Right Shift ";
    break;
  case SDLK_LSHIFT:
    rtrn += "Left Shift ";
    break;
  case SDLK_RCTRL:
    rtrn += "Right Control ";
    break;
  case SDLK_LCTRL:
    rtrn += "Left Control ";
    break;
  case SDLK_RALT:
    rtrn += "Right Alt ";
    break;
  case SDLK_LALT:
    rtrn += "Left Alt ";
    break;
  case SDLK_RMETA:
    rtrn += "Right Meta ";
    break;
  case SDLK_LMETA:
    rtrn += "Left Meta ";
    break;
  case SDLK_LSUPER:
    rtrn += "Left windows ";
    break;
  case SDLK_RSUPER:
    rtrn += "Right windows ";
    break;
  case SDLK_MODE:
    rtrn += "Mode ";
    break;
  case SDLK_HELP:
    rtrn += "Help ";
    break;
  case SDLK_PRINT:
    rtrn += "Print Screen ";
    break;
  case SDLK_SYSREQ:
    rtrn += "SysRq ";
    break;
  case SDLK_BREAK:
    rtrn += "Break ";
    break;
  case SDLK_MENU:
    rtrn += "Menu ";
    break;
  case SDLK_POWER:
    rtrn += "Power ";
    break;
  case SDLK_EURO:
    rtrn += "Euro ";
    break;
  default:
    rtrn += (char)unicode;
    rtrn += ' ';
    break;


  }
  return rtrn;
}

const EVENT_RESULT TestEvents::keyDown(const SDLKey sym, const SDLMod mod, const Uint16 unicode) {
  cout<<printKeys(sym, mod, unicode)<<"down"<<endl;
  return EVENT_SUCCESS;
}
const EVENT_RESULT TestEvents::keyPressed(const SDLKey sym, const SDLMod mod, const Uint16 unicode) {
  cout<<printKeys(sym, mod, unicode)<<"pressed"<<endl;
  return EVENT_SUCCESS;
}
const EVENT_RESULT TestEvents::keyUp(const SDLKey sym, const SDLMod mod, const Uint16 unicode) {
  cout<<printKeys(sym, mod, unicode)<<"up"<<endl;
  return EVENT_SUCCESS;
}
const EVENT_RESULT TestEvents::keyReleased(const SDLKey sym, const SDLMod mod, const Uint16 unicode) {
  cout<<printKeys(sym, mod, unicode)<<"released"<<endl;
  return EVENT_SUCCESS;
}

const EVENT_RESULT TestEvents::mouseMove(const int mX, const int mY, const int relX, const int relY, const bool lDown, const bool rDown, const bool mDown) {
  cout<<"Mouse moved to ("<<mX<<", "<<mY<<") with a relative movement of ("<<relX<<", "<<relY<<") "<<endl;
  cout<<"The left mouse button is "<<(lDown? "down":"up")<<endl;
  cout<<"The right mouse button is "<<(rDown? "down":"up")<<endl;
  cout<<"The middle mouse button is "<<(mDown? "down":"up")<<endl;
  return EVENT_SUCCESS;
}

const EVENT_RESULT TestEvents::mouseButtonDown(const Uint8 button, const int mX, const int mY) {
  switch(button)
  {
  case MOUSE_LEFT:
    cout<<"Left mouse button";
    break;
  case MOUSE_RIGHT:
    cout<<"Right mouse button";
    break;
  case MOUSE_MIDDLE:
    cout<<"Middle mouse button";
    break;
  }
  cout<<" down at ("<<mX<<", "<<mY<<")"<<endl;
  return EVENT_SUCCESS;
}

const EVENT_RESULT TestEvents::mouseButtonPressed(const Uint8 button, const int mX, const int mY) {
  switch(button)
  {
  case MOUSE_LEFT:
    cout<<"Left mouse button";
    break;
  case MOUSE_RIGHT:
    cout<<"Right mouse button";
    break;
  case MOUSE_MIDDLE:
    cout<<"Middle mouse button";
    break;
  }
  cout<<" pressed at ("<<mX<<", "<<mY<<")"<<endl;
  return EVENT_SUCCESS;
}

const EVENT_RESULT TestEvents::mouseButtonUp(const Uint8 button, const int mX, const int mY) {
  switch(button)
  {
  case MOUSE_LEFT:
    cout<<"Left mouse button";
    break;
  case MOUSE_RIGHT:
    cout<<"Right mouse button";
    break;
  case MOUSE_MIDDLE:
    cout<<"Middle mouse button";
    break;
  }
  cout<<" up at ("<<mX<<", "<<mY<<")"<<endl;
  return EVENT_SUCCESS;
}
const EVENT_RESULT TestEvents::mouseButtonReleased(const Uint8 button, const int mX, const int mY) {
  switch(button)
  {
  case MOUSE_LEFT:
    cout<<"Left mouse button";
    break;
  case MOUSE_RIGHT:
    cout<<"Right mouse button";
    break;
  case MOUSE_MIDDLE:
    cout<<"Middle mouse button";
    break;
  }
  cout<<" released at ("<<mX<<", "<<mY<<")"<<endl;
  return EVENT_SUCCESS;
}

const EVENT_RESULT TestEvents::joyAxis(const Uint8 which, const Uint8 axis, const Sint16 value) {
  cout<<"Axis "<<axis<<" of joystick "<<which<<" has a value of "<<value<<endl;
  return EVENT_SUCCESS;
}

const EVENT_RESULT TestEvents::joyButtonDown(const Uint8 which, const Uint8 button) {
  cout<<"Button "<<button<<" of joystick "<<which<<" is down"<<endl;
  return EVENT_SUCCESS;
}

const EVENT_RESULT TestEvents::joyButtonPressed(const Uint8 which, const Uint8 button) {
  cout<<"Button "<<button<<" of joystick "<<which<<" was pressed"<<endl;
  return EVENT_SUCCESS;
}

const EVENT_RESULT TestEvents::joyButtonUp(const Uint8 which, const Uint8 button) {
  cout<<"Button "<<button<<" of joystick "<<which<<" is up"<<endl;
  return EVENT_SUCCESS;
}

const EVENT_RESULT TestEvents::joyButtonReleased(const Uint8 which, const Uint8 button) {
  cout<<"Button "<<button<<" of joystick "<<which<<" was released"<<endl;
  return EVENT_SUCCESS;
}

const EVENT_RESULT TestEvents::joyHatChange(const Uint8 which, const Uint8 hat, const Uint8 value) {
  cout<<"Hat "<<hat<<" of joystick "<<which<<" is now "<<value<<endl;
  return EVENT_SUCCESS;
}

const EVENT_RESULT TestEvents::joyBallMove(const Uint8 which, const Uint8 ball, const Sint16 xRel, const Sint16 yRel) {
  cout<<"Ball "<<ball<<" of joystick "<<which<<" moved at <"<<xRel<<", "<<yRel<<">"<<endl;
  return EVENT_SUCCESS;
}

const EVENT_RESULT TestEvents::unhandledSystemEvent(SDL_SysWMmsg * const msg) {
  cout<<"Encountered unhandled system msg"<<endl;
  return EVENT_SUCCESS;
}

const EVENT_RESULT TestEvents::userEvent(const int code, void * const data1, void * const data2) {
  cout<<"User event with code of "<<code<<" was encountered"<<endl;
  return EVENT_SUCCESS;
}

}
