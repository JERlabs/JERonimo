#include "DataManager.h"

namespace GameControl {

const int DataManager::init() {
  Running = true;
  return 0;
}

const bool DataManager::running() {
  return Running;
}

}
