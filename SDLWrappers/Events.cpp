#include "Events.h"

namespace jer {
  Events *Events::eventListener;
  Uint32 Events::timestamp;
  
  shared_ptr<EventLoop> EventLoop::instance(new EventLoop);
  
  const SUCCESS Events::PollEvents()
  {
      if(eventListener == NULL)
          return FAILED;
      
      SUCCESS ret = 0;
      SDL_Event event;
      
      while(SDL_PollEvent(&event))
      {
          if(ret < 0)
              continue;
          timestamp =  event.common.timestamp;
          ret = eventListener->handleEvent(&event);
      }
      
      return ret;
  }
  
  
  Events::Events() {
     App::GetApp().loadVideo();
     App::GetApp().loadEvents();
  }

  Events::~Events() {
  }

  const SUCCESS Events::handleEvent(const SDL_Event * const Event)
  {
    switch(Event->type)
    {  //newline brackets implemented since this is a lot of nesting
    case SDL_WINDOWEVENT: ///Some sort of input or output gained or lost
      {
        const Uint8 &winID = Event->window.windowID;
        switch(Event->window.event) 
        {
        case SDL_WINDOWEVENT_ENTER:   ///Mouse message handling gained or lost
          return mouseEnter(winID);
          
        case SDL_WINDOWEVENT_LEAVE:   ///General input message handling gained or lost
          return mouseLeave(winID);

        case SDL_WINDOWEVENT_MINIMIZED:   ///Output to the screen at all gained or lost
          return minimized(winID);
          
        case SDL_WINDOWEVENT_RESTORED:
          return restored(winID);
          
        case SDL_WINDOWEVENT_MAXIMIZED:
          return maximized(winID);
          
        case SDL_WINDOWEVENT_SHOWN:
          return shown(winID);
          
        case SDL_WINDOWEVENT_HIDDEN:
          return hidden(winID);
          
        case SDL_WINDOWEVENT_EXPOSED:
          return exposed(winID);
          
        case SDL_WINDOWEVENT_FOCUS_GAINED:
          return keyboardFocusGain(winID);
          
        case SDL_WINDOWEVENT_FOCUS_LOST:
          return keyboardFocusLost(winID);
          
        case SDL_WINDOWEVENT_RESIZED:
          return resized(winID, Dimensions<int>(Event->window.data1, Event->window.data2));
          
        case SDL_WINDOWEVENT_MOVED:
          return moved(winID, Point<int>(Event->window.data1, Event->window.data2));
          
        case SDL_WINDOWEVENT_CLOSE:
          return windowExited(winID);
          
        default:   ///For some reason there is an unknown window event
          return FAILED;
        }
        break;
      }
    case SDL_KEYDOWN:
      {
        if(Event->key.repeat)
        {
          return keyHeld(Event->key.windowID, Event->key.keysym);
        }
        else
        {
          return keyPressed(Event->key.windowID, Event->key.keysym);
        }
        break;
      }
    case SDL_KEYUP:
        return keyReleased(Event->key.windowID, Event->key.keysym);
        
    case SDL_TEXTINPUT:
        return textInput(Event->text.windowID, Event->text.text);
        
    case SDL_TEXTEDITING:
        return textEdit(Event->edit.windowID, Event->edit.text, Event->edit.start, Event->edit.length);
        
    case SDL_MOUSEMOTION:
      return mouseMove(Event->motion.windowID, Event->motion.which,
                       Delta<Point<int> >(Point<int>(Event->motion.xrel, Event->motion.yrel), 
                                          Point<int>(Event->motion.x, Event->motion.y)),
                       bitset<N_MOUSE_BUTTONS>(Event->motion.state));
                       
    case SDL_MOUSEBUTTONDOWN:
      return mouseButtonPressed(Event->button.windowID, Event->button.which, Event->button.button, Event->button.clicks,
                                Point<int>(Event->button.x, Event->button.y));
      
    case SDL_MOUSEBUTTONUP:
        return mouseButtonPressed(Event->button.windowID, Event->button.which, Event->button.button, Event->button.clicks,
                                  Point<int>(Event->button.x, Event->button.y));
     
    case SDL_MOUSEWHEEL:
        return mouseWheel(Event->wheel.windowID, Event->wheel.which, Point<int>(Event->wheel.x, Event->wheel.y));
        
    case SDL_JOYAXISMOTION:
      return joyAxis(Event->jaxis.which, Event->jaxis.axis, Event->jaxis.value);
    
    case SDL_JOYBUTTONDOWN:
      return joyButtonPressed(Event->jbutton.which, Event->jbutton.button);
      
    case SDL_JOYBUTTONUP:
      return joyButtonReleased(Event->jbutton.which, Event->jbutton.button);
      
    case SDL_JOYHATMOTION:
      return joyHatChange(Event->jhat.which, Event->jhat.hat, Event->jhat.value);
        
    case SDL_JOYBALLMOTION:
      return joyBallMove(Event->jball.which, Event->jball.ball, Point<int>(Event->jball.xrel, Event->jball.yrel));
      
    case SDL_DROPFILE:
    {
      const SUCCESS ret = droppedFile(Event->drop.file);
      SDL_free(Event->drop.file);
      return ret;
    }
      
    case SDL_SYSWMEVENT:
      return unhandledSystemEvent(Event->syswm.msg);
     
    case SDL_QUIT:
      return appExited();
        
    case SDL_USEREVENT:
    default:
      {
        return userEvent(Event->user.windowID, Event->user.code, Event->user.data1, Event->user.data2);
      }
    }

    return FAILED;
  }
}
