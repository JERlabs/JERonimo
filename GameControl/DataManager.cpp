#include "DataManager.h"

namespace jer {

const int DataManager::init() {
  Running = true;
  return 0;
}

const bool DataManager::running() {
  return Running;
}

}
