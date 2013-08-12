#include "Space2D/Vector.h"
#include "Space2D/Velocity.h"
#include "GameControl/App.h"
#include "GameControl/GameLoop.h"
#include "GameControl/DataManager.h"
#include "SurfaceX/DoubleSurf.h"

using namespace Space2D;
using namespace GameControl;
using namespace SurfaceX;

class SurfaceTestDM;
class SurfaceTestGL;

class SurfaceTestDM: public DataManager {
public:
  DoubleSurf varPic;   //experiment variable
  SimpleSurf controlPic; //experiment control
  char *picFile;
  Vector mouse;  // Angle equals angle of surfs. Magnitude equals zoom of pics
  Point center;
  
public:
  SurfaceTestDM() {
    currentGL = NULL;
  }
  const int init() {
    Running = true;
    
    if(1) {
      if(varPic.load(picFile)) {
	cout<<"Failed to load, exiting"<<endl;
	return -1;
      }
      controlPic.set(varPic.copy());
    }
    
    
    center.x(Display->w/2);
    center.y(Display->h/2);
    
    mouse.setMag(1);
    
    return 0;
  };
  
  GameLoop * const firstGameLoop(App *parent);
  
  ~SurfaceTestDM();
  
};


class SurfaceTestGL: public GameLoop {
public:
  SurfaceTestDM *MyDataM;
  
  const int init() {
    Running = true;
    return 0;
  };
  
  int const loop() {
    return 0;
  };
  
  int const render() const {
    SDL_FillRect(MyDataM->Display, NULL, SDL_MapRGB(MyDataM->Display->format, 0, 0, 0));
    if(MyDataM->controlPic.draw(MyDataM->Display, Point(0, 0))) {
      return -1;
    }
    if(MyDataM->varPic.draw(MyDataM->Display, Point(MyDataM->center.x(), 0))) {
      return -1;
    }
    SDL_Flip(MyDataM->Display);
    return 0;
  }
  
  const EVENT_RESULT exited() {
    Running = false;
    return EVENT_SUCCESS;
  }
  
 /* const EVENT_RESULT mouseMove(const int mX, const int mY, const int relX, const int relY,
			       const bool lDown, const bool rDown, const bool mDown) {
    static Vector mousePrev;
    static bool first = true;
    Point mPos(mX, mY);
    MyDataM->mouse = mPos - MyDataM->center;
    
    if(first) {
      mousePrev = MyDataM->mouse;
      first = false;
    }
    
    MyDataM->varPic.set(rotozoomSurface(MyDataM->varPic, RAD_TO_DEGREES(MyDataM->mouse.theta()),
				       1, false));
    
    MyDataM->controlPic.set(rotozoomSurface(MyDataM->controlPic, RAD_TO_DEGREES(MyDataM->mouse.theta() - mousePrev.theta()),
					    1, false));
    
    mousePrev = MyDataM->mouse;
    
    return EVENT_SUCCESS;
  };
  */
 
  const EVENT_RESULT keyDown(const SDLKey sym, const SDLMod mod, const Uint16 unicode) {
    long double turn = 0, scale = 1;
    switch(sym)
    {
    case SDLK_LEFT:
      MyDataM->mouse.theta(MyDataM->mouse.theta() - 1.0);
      turn = -1.0;
      break;
    case SDLK_RIGHT:
      MyDataM->mouse.theta(MyDataM->mouse.theta() + 1.0);
      turn = 1.0;
      break;
    case SDLK_UP:
      MyDataM->mouse*=1.02;
      scale = 1.02;
      break;
    case SDLK_DOWN:
      MyDataM->mouse*=0.98;
      scale = 0.98;
      break;
    case SDLK_SPACE:
      return MyDataM->init();
    default:
      return EVENT_SUCCESS;
    }
    
    
    MyDataM->varPic.set(rotozoomSurface(MyDataM->varPic, MyDataM->mouse.theta(),
				       MyDataM->mouse.mag(), true));
    
    
    MyDataM->controlPic.set(rotozoomSurface(MyDataM->controlPic, turn,
					    scale, true));
    return EVENT_SUCCESS;
  };
  
  const EVENT_RESULT keyPressed(const SDLKey sym, const SDLMod mod, const Uint16 unicode) {
    return keyDown(sym, mod, unicode);
  };
    
  
  
  const EVENT_RESULT resized(const int W, const int H) {
    MyDataM->Display = SDL_SetVideoMode(W, H, 32, SDL_DOUBLEBUF | SDL_HWSURFACE | SDL_RESIZABLE);
    MyDataM->center.x(W/2);
    MyDataM->center.y(H/2);
    return EVENT_SUCCESS;
  }
  
  const int cleanup() {return 0;};
  
  SurfaceTestGL(SurfaceTestDM * const DM, GameLoop * const parent): GameLoop(*DM, *parent) {
    MyDataM = DM;
  }
  
};

GameLoop * const SurfaceTestDM::firstGameLoop(App *parent) {
  if(currentGL == NULL)
    currentGL = new SurfaceTestGL(this, parent);
  return currentGL;
}

SurfaceTestDM::~SurfaceTestDM() {
  delete currentGL;
}


int main(int argc, char *argv[]) {
  if(argc < 2)
  {
    cout<<endl<<"Call with test pic"<<endl;
    return 0;
  }
  
  cout<<endl<<"Welcome to DoubleSurf Test"<<endl;
  cout<<"On the left we have a regular Simple Surface which does not keep the original surface intact"<<endl;
  cout<<"On the right we have a Double Surface which continuously uses the original surface during manipulation"<<endl;
  cout<<"To see the difference, manipulate the surfaces with the following controls"<<endl;
  cout<<"Right: rotate clockwise"<<endl<<"Left: rotate counter-clockwise"<<endl;
  cout<<"Up: Increase size"<<endl<<"Down: Decrease size"<<endl;
  cout<<"Space: reset"<<endl;
  cout<<"Enter Key: continue";  
  while(getchar() != '\n');
  
  SurfaceTestDM mySurfTestDM;
  mySurfTestDM.picFile = argv[1];
  App myApp(&mySurfTestDM, SDL_INIT_EVERYTHING, 640, 480, 32, SDL_DOUBLEBUF | SDL_HWSURFACE | SDL_RESIZABLE);
  return myApp.run();
}