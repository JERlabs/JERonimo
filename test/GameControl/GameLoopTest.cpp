#include "GameControl/GameLoop.h"
#include <iostream>

using namespace GameControl;
using std::cout;
using std::endl;

class MyLoop: public GameLoop {
  private:
    int Loopnum;
  protected:
    int const init() {
      cout << "Starting MyLoop" << endl;
      return 0;
    }
    int const loop() {
      cout << "PHYSICS" << endl;
      if(Loopnum++ > 5) {
        Running = false;
      }
      return 0;
    }
    int const render() const{
      cout << "PRETTY" << endl;
      if(Loopnum > 5) {
        cout << "CLEANUP TIME!" << endl;
      }
      return 0;
    }
    int const cleanup() {
      cout << "Cleanup, Cleanup, Everybody Everywhere." << endl;
    }
    EVENT_RESULT const exited() {
      Running = false;
    }
};

int main(int argc, char* argv[]) {
  MyLoop olo = MyLoop();
  GameLoop* lol = &olo;
  lol->run(NULL);
} 
  
