#include "Events.h"

namespace GameControl {
  bitset<NUM_KEYS> Events::keys(0);
  bitset<NUM_MOUSE_BUTTON> Events::mouseButtons(0);
  vector<bool> Events::joystickButtons;

  Events::Events() {
  }

  Events::~Events() {
  }

  const EVENT_RESULT Events::handleEvent(SDL_Event * const Event)
  {
    switch(Event->type)
    {  //newline brackets implemented since this is a lot of nesting
    case SDL_ACTIVEEVENT: ///Some sort of input or output gained or lost
      {
        switch(Event->active.state) 
        {
        case SDL_APPMOUSEFOCUS:   ///Mouse message handling gained or lost
          return Event->active.gain? mouseFocus():mouseBlur();
          
        case SDL_APPINPUTFOCUS:   ///General input message handling gained or lost
          return Event->active.gain? inputFocus():inputBlur();

        case SDL_APPACTIVE:   ///Output to the screen at all gained or lost
          return Event->active.gain? restored():minimized();

        default:   ///For some reason there is an unknown ACTIVITY gain or loss state
          return EVENT_FAILURE;
        }
        break;
      }
    case SDL_KEYDOWN:
      {
        if(keys[Event->key.keysym.sym])
        {
          return keyDown(Event->key.keysym.sym, Event->key.keysym.mod, Event->key.keysym.unicode);
        }
        else
        {
          keys[Event->key.keysym.sym] = 1;
          return keyPressed(Event->key.keysym.sym, Event->key.keysym.mod, Event->key.keysym.unicode);
        }
        break;
      }
    case SDL_KEYUP:
      {
        if(keys[Event->key.keysym.sym])
        {
          keys[Event->key.keysym.sym] = 0;
          return keyReleased(Event->key.keysym.sym, Event->key.keysym.mod, Event->key.keysym.unicode);
        }
        else
        {
          return keyPressed(Event->key.keysym.sym, Event->key.keysym.mod, Event->key.keysym.unicode);
        }
        break;
      }
    case SDL_MOUSEMOTION:
      return mouseMove(Event->motion.x, Event->motion.y, Event->motion.xrel, Event->motion.yrel,
        Event->motion.state & SDL_BUTTON(SDL_BUTTON_LEFT), Event->motion.state & SDL_BUTTON(SDL_BUTTON_RIGHT),
        Event->motion.state & SDL_BUTTON(SDL_BUTTON_MIDDLE)); 
      break;
    case SDL_MOUSEBUTTONDOWN:
      {
        if(mouseButtons[Event->button.button])
        {
          return mouseButtonDown(Event->button.button, Event->button.x, Event->button.y);
        }
        else
        {
          mouseButtons[Event->button.button] = 1;
          return mouseButtonPressed(Event->button.button, Event->button.x, Event->button.y);
        }
        break;
      }
    case SDL_MOUSEBUTTONUP:
      {
        if(mouseButtons[Event->button.button])
        {
          mouseButtons[Event->button.button] = 0;
          return mouseButtonReleased(Event->button.button, Event->button.x, Event->button.y);
        }
        else
        {
          return mouseButtonUp(Event->button.button, Event->button.x, Event->button.y);
        }
        break;
      }
    case SDL_JOYAXISMOTION:
      return joyAxis(Event->jaxis.which, Event->jaxis.axis, Event->jaxis.value);
      break;
    case SDL_JOYBUTTONDOWN:
    case SDL_JOYBUTTONUP:
      {
        if(joystickButtons.size() >= Event->jbutton.button)
        {
          for(Uint8 i = joystickButtons.size(); i < Event->jbutton.button; i++) //makes sure it accounts for the correct number of joystick buttons.
            joystickButtons.push_back(0);
        }
        if(Event->type = SDL_JOYBUTTONDOWN)
        {
          if(joystickButtons[Event->jbutton.button])
          {
           return joyButtonDown(Event->jbutton.which, Event->jbutton.button);
          }
          else
          {
            joystickButtons[Event->jbutton.button] = 1;
            return joyButtonPressed(Event->jbutton.which, Event->jbutton.button);
          }
        }
        else
        {
          if(joystickButtons[Event->jbutton.button])
          {
            joystickButtons[Event->jbutton.button] = 0;
            return joyButtonReleased(Event->jbutton.which, Event->jbutton.button);
          }
          else
          {
            return joyButtonUp(Event->jbutton.which, Event->jbutton.button);
          }
        }
        break;
      }

      //TODO: Complete the Event handles.
    }

    return false;
  }
}