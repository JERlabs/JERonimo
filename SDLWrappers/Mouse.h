#include <bitset>
#include <unordered_map>

#include "Declarations.h"
#include "App.h"
#include "Window.h"

namespace jer
{
    using std::bitset;
    using std::unordered_map;
    using std::shared_ptr;  
    
    class Mouse
    {
    public:
        enum {LEFT=SDL_BUTTON_LEFT, MIDDLE=SDL_BUTTON_MIDDLE, RIGHT=SDL_BUTTON_RIGHT, 
            X1=SDL_BUTTON_X1, X2=SDL_BUTTON_X2, N_BUTTONS};
            
            
    private:
        static unordered_map<Uint32, Mouse *> mouses;
        static Mouse& MutateMouse(const Uint32 id);
        
    public:
        static const Mouse& GetMouse(const Uint32 id);
        static const Mouse& GetMouse();
        
    private:
        static void ButtonEvent(SDL_MouseButtonEvent * const e);
        static void MotionEvent(SDL_MouseMotionEvent * const e);
        
    private:
        bitset<N_BUTTONS> buttonStates;
        Point<int> position;
        Window *mouseFocus;
        //Uint32 id;
        
    private:
        ~Mouse() {};
        Mouse(): position(0, 0), mouseFocus(NULL) {};
        Mouse(const Mouse& other): buttonStates(other.buttonStates), position(other.position), mouseFocus(other.mouseFocus) {};
        //explicit Mouse(const Uint32 ID): buttonStates(0), position(0, 0), mouseFocus(NULL), id(ID) {};
        //Mouse(const Mouse& other): Mouse(other.id) {};
        
    public:
        const bool getButton(const Uint8 butt) const {return butt >= N_BUTTONS? false:buttonStates[butt];};
        const Point<int> &getPosition() const {return position;};
        Window * const getFocusedWindow() const {return mouseFocus;};
        
    private:
        void updateButton(const Uint8 butt, const bool state);
        void updatePosition(const Point<int> &p) {position=p;};
        void updateFocus(Window * const win) {mouseFocus = win;};
        void updateFocus(const Uint32 winID) {mouseFocus = Window::GetWindow(winID);};
    };
}