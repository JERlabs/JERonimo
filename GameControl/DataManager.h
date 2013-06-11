#ifndef _DATA_MANAGER_H_
#define _DATA_MANAGER_H_

#include "GameControl.h"

namespace GameControl {

class DataManager {
  public:
    /// Run by App before the first GameLoop is run
    int virtual init()=0;
};

}
#endif /*_DATA_MANAGER_H_*/
