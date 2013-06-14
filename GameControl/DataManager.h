#ifndef _DATA_MANAGER_H_
#define _DATA_MANAGER_H_

#include "GameControl.h"
#include "GameLoop.h"

namespace GameControl {

class DataManager {
  protected:
    GameLoop* currentGL;
  public:
    /// Run by App before the first GameLoop is run
    int virtual init()=0;
    
    virtual GameLoop * firstGameLoop(App* parent)=0;
};

}
#endif /*_DATA_MANAGER_H_*/
