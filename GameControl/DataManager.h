#ifndef _DATA_MANAGER_H_
#define _DATA_MANAGER_H_

#include "Declarations.h"
#include "GameLoop.h"

namespace jer {

class DataManager {
  protected:
    GameLoop* currentGL;
  public:
    bool Running;
  public:
    SDL_Surface *Display;
  public:
    /// Run by any GameLoop introducing new data to be loaded before the first GameLoop is run
    virtual const int init();
    
    virtual const bool running();
    
    virtual GameLoop * const firstGameLoop(App* parent)=0;
    
  public:
    virtual ~DataManager() {};
  
};

}
#endif /*_DATA_MANAGER_H_*/
