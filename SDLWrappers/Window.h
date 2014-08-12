#ifndef _WINDOW_H_
#define _WINDOW_H_

#include <memory>
#include <string>

#include "Declarations.h"
#include "ControlInterfaces/Loadable.h"
#include "Space2D.h"

namespace jer
{
    using std::shared_ptr;
    using std::string;
    
    class Window: public Loadable
    {
    public:
        enum {FULLSCREEN=SDL_WINDOW_FULLSCREEN, 
                      FULLSCREEN_DESKTOP=SDL_WINDOW_FULLSCREEN_DESKTOP,
                      OPENGL=SDL_WINDOW_OPENGL,
                      SHOWN=SDL_WINDOW_SHOWN,
                      HIDDEN=SDL_WINDOW_HIDDEN,
                      BORDERLESS=SDL_WINDOW_BORDERLESS,
                      RESIZABLE=SDL_WINDOW_RESIZABLE,
                      MINIMIZED=SDL_WINDOW_MINIMIZED,
                      MAXIMIZED=SDL_WINDOW_MAXIMIZED,
                      INPUT_GRABBED=SDL_WINDOW_INPUT_GRABBED,
                      INPUT_FOCUS=SDL_WINDOW_INPUT_FOCUS,
                      MOUSE_FOCUS=SDL_WINDOW_MOUSE_FOCUS,
                      FOREIGN=SDL_WINDOW_FOREIGN,
                      ALLOW_HIGHDPI=SDL_WINDOW_ALLOW_HIGHDPI//,
                      //MOUSE_CAPTURE=SDL_WINDOW_MOUSE_CAPTURE
        };
        
    private:
        SDL_Window *win;
        // Initialization values
        mutable string name;                //< Window title
        mutable Point<int> screenPosition;  //< Window position in pixels
        mutable Dimensions<int> windowSize; //< Window size in pixels
        mutable Uint32 flags;               //< Flags with which to initialize the window
        Uint32 id;                          //< ID of the window
        
    public:
        virtual ~Window() {if(isLoaded()) unload();};
        Window(): win(NULL), screenPosition(-1, -1), flags(0), id(0) {};
        Window(const string &title, const Point<int> &position, const Dimensions<int> &size, const Uint32 initFlags=0):
            win(NULL), name(title), screenPosition(position), windowSize(size), flags(initFlags) {};
            
    public:
        virtual const SUCCESS load() override;
        virtual const SUCCESS unload() override;
        
    public:
        const string &getName() const;
        const Point<int> &getPosition() const;
        const Dimensions<int> &getSize() const;
        const Uint32 getFlags() const;
        const bool hasFlags(const Uint32 f) const;
        const Uint32 getID() const {return id;};
        SDL_Window * const getWindow() {return win;};
        const SDL_Window * const getWindow() const {return win;};
        
    public:
        void setName(const string& n);
        void setPosition(const Point<int> &p);
        void setSize(const Dimensions<int> &d);
        void setInitFlags(const Uint32 f) {flags = f;};
        void addInitFlags(const Uint32 f) {flags |= f;};
        void removeInitFlags(const Uint32 f) {flags ^= flags & f;};
        
        void hide();
        void show();
        void maximize();
        void minimize();
        void makeFullScreen();
        void makeFullScreenDesktop();
        void makeWindowed();
        void grabInput();
        void releaseInput();
        void setGrab(const bool grab);
    };
}

#endif /*_WINDOW_H_*/