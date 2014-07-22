#ifndef _TESTEVENTS_H_
#define _TESTEVENTS_H_

#include "GameLoop.h"

namespace jer {

class TestEvents: public GameLoop {
protected:
  virtual int const init();
  virtual int const loop();
  virtual int const render() const;
  virtual int const cleanup();
public:
  TestEvents(DataManager * const dataM, GameLoop * const parent);
  TestEvents(DataManager &dataM, GameLoop &parent);
protected:
  const EVENT_RESULT inputFocus();
  const EVENT_RESULT inputBlur();
  const EVENT_RESULT mouseFocus();
  const EVENT_RESULT mouseBlur();
  const EVENT_RESULT minimized();
  const EVENT_RESULT restored();
  const EVENT_RESULT resized(const int W, const int H);
  const EVENT_RESULT exposed();
  const EVENT_RESULT exited();
  string printKeys(const SDLKey sym, const SDLMod mod, const Uint16 unicode);
  const EVENT_RESULT keyDown(const SDLKey sym, const SDLMod mod, const Uint16 unicode);
  const EVENT_RESULT keyPressed(const SDLKey sym, const SDLMod mod, const Uint16 unicode);
  const EVENT_RESULT keyUp(const SDLKey sym, const SDLMod mod, const Uint16 unicode);
  const EVENT_RESULT keyReleased(const SDLKey sym, const SDLMod mod, const Uint16 unicode);
  const EVENT_RESULT mouseMove(const int mX, const int mY, const int relX, const int relY, const bool lDown, const bool rDown, const bool mDown);
  const EVENT_RESULT mouseButtonDown(const Uint8 button, const int mX, const int mY);
  const EVENT_RESULT mouseButtonPressed(const Uint8 button, const int mX, const int mY);
  const EVENT_RESULT mouseButtonUp(const Uint8 button, const int mX, const int mY);
  const EVENT_RESULT mouseButtonReleased(const Uint8 button, const int mX, const int mY);
  const EVENT_RESULT joyAxis(const Uint8 which, const Uint8 axis, const Sint16 value);
  const EVENT_RESULT joyButtonDown(const Uint8 which, const Uint8 button);
  const EVENT_RESULT joyButtonPressed(const Uint8 which, const Uint8 button);
  const EVENT_RESULT joyButtonUp(const Uint8 which, const Uint8 button);
  const EVENT_RESULT joyButtonReleased(const Uint8 which, const Uint8 button);
  const EVENT_RESULT joyHatChange(const Uint8 which, const Uint8 hat, const Uint8 value);
  const EVENT_RESULT joyBallMove(const Uint8 which, const Uint8 ball, const Sint16 xRel, const Sint16 yRel);
  const EVENT_RESULT unhandledSystemEvent(SDL_SysWMmsg * const msg);
  const EVENT_RESULT userEvent(const int code, void * const data1, void * const data2);
};

}


#endif
