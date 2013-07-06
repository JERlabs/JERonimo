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
  const int init() {
    Running = true;
    currentGL = NULL;
    
    if(varPic == NULL) {
      if(varPic.load(picFile)) {
	cout<<"Failed to load, exiting"<<endl;
	return -1;
      }
      controlPic.set(varPic.get());
    }
    
    
    center.x(Display->w/2);
    center.y(Display->h/2);
    
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
    if(MyDataM->controlPic.draw(MyDataM->Display, Point(MyDataM->center.x()/2, MyDataM->center.y()))) {
      return -1;
    }
    if(MyDataM->varPic.draw(MyDataM->Display, Point(MyDataM->center.x()*3.0/2.0, MyDataM->center.y()))) {
      return -1;
    }
    SDL_Flip(MyDataM->Display);
    return 0;
  }
  
  const EVENT_RESULT exited() {
    Running = false;
    return EVENT_SUCCESS;
  }
  
  const EVENT_RESULT mouseMove(const int mX, const int mY, const int relX, const int relY,
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
				       2*MyDataM->mouse.mag()/Vector(MyDataM->center*2).mag(), false));
    
    MyDataM->controlPic.set(rotozoomSurface(MyDataM->controlPic, RAD_TO_DEGREES(MyDataM->mouse.theta() - mousePrev.theta()),
					    MyDataM->mouse.mag()/mousePrev.mag(), false));
    
    mousePrev = MyDataM->mouse;
    
    return EVENT_SUCCESS;
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
  SurfaceTestDM mySurfTestDM;
  mySurfTestDM.picFile = argv[1];
  App myApp(&mySurfTestDM, SDL_INIT_EVERYTHING, 640, 480, 32, SDL_DOUBLEBUF | SDL_HWSURFACE | SDL_RESIZABLE);
  return myApp.run();
}