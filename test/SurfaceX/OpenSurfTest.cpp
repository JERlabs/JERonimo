#include "SurfaceX/OpenSurf.h"
#include "GameControl/App.h"
#include "GameControl/DataManager.h"

using namespace GameControl;
using namespace SurfaceX;
using namespace Space2D;

class SurfaceTestDM;
class SurfaceTestGL;

class SurfaceTestDM: public DataManager {
public:
  OpenSurf testPic;
  char *picFile;
  Point testLoc;
  
public:
  const int init() {
    Running = true;
    currentGL = NULL;
    SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY, SDL_DEFAULT_REPEAT_INTERVAL);
    SDL_EnableUNICODE(1);
    
    if(testPic.Surf() == NULL) {
      if(!testPic.load(picFile)) {
	cout<<"Failed to load, exiting"<<endl;
	return 1;
      }
      Uint8 r=0, g=255, b=0;
      //SDL_GetRGB(*((Uint32 *)testPic->pixels), testPic->format, &r, &g, &b);
      transparentSurf(testPic, r, g, b);
    }
    
    testLoc.x(100);
    testLoc.y(100);
       
    return 0;
  };
  
  GameLoop * const firstGameLoop(App *parent);
  
  ~SurfaceTestDM();
  
};


class SurfaceTestGL: public GameLoop {
public:
  SurfaceTestDM *MyDataM;
  int const loop() {
    return 0;
  };
  
  int const render() const {
    SDL_FillRect(MyDataM->Display, NULL, SDL_MapRGB(((SDL_Surface *)(MyDataM->testPic))->format, 0, 0, 0));
    if(!MyDataM->testPic.draw(MyDataM->Display, MyDataM->testLoc)) {
      return 1;
    }
    SDL_Flip(MyDataM->Display);
    return 0;
  }
  
  const EVENT_RESULT exited() {
    Running = false;
    return EVENT_SUCCESS;
  }
  
  const EVENT_RESULT keyDown(const SDLKey sym, const SDLMod mod, const Uint16 unicode) {
    static Point R(1, 0), L(-1, 0), U(0, -1), D(0, 1);
    static Uint8 r=0, g=0, b=0;
    switch(sym)
    {
    case SDLK_RIGHT:
      MyDataM->testLoc += R;
      break;
    case SDLK_LEFT:
      MyDataM->testLoc += L;
      break;
    case SDLK_UP:
      MyDataM->testLoc += U;
      break;
    case SDLK_DOWN:
      MyDataM->testLoc += D;
      break;
    case SDLK_g:
      cout<<"G: "<<(int)++g<<endl;
      break;
    case SDLK_f:
      cout<<"G: "<<(int)--g<<endl;
      break;
    case SDLK_r:
      cout<<"R: "<<(int)++r<<endl;
      break;
    case SDLK_e:
      cout<<"R: "<<(int)--r<<endl;
      break;
    case SDLK_b:
      cout<<"B: "<<(int)++b<<endl;
      break;
    case SDLK_v:
      cout<<"B: "<<(int)--b<<endl;
      break;      
    default:
      break;
    }
    
    //transparentSurf(MyDataM->testPic, r, g, b);
    SDL_SetColorKey(MyDataM->testPic, SDL_SRCCOLORKEY | SDL_RLEACCEL, SDL_MapRGB(MyDataM->testPic->format, r, g, b));
    return EVENT_SUCCESS;
  };
  
  const EVENT_RESULT keyPressed(const SDLKey sym, const SDLMod mod, const Uint16 unicode) {
    return keyDown(sym, mod, unicode);
  };
  
  const EVENT_RESULT resized(const int W, const int H) {
    MyDataM->Display = SDL_SetVideoMode(W, H, 32, SDL_DOUBLEBUF | SDL_HWSURFACE | SDL_RESIZABLE);
    return EVENT_SUCCESS;
  }
  
  const int cleanup() {return 0;};
  const int init() {
    Running = true;
    return 0;
  };
  
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