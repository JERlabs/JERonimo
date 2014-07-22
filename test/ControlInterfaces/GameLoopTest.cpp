#include "ControlInterfaces.h"
#include <iostream>
#include <cstdlib>

using namespace jer;

class TestLoop: public GameLoop
{
    int *primes;
    int current;
    int stop;
    
protected:
    const SUCCESS loop()
    {
        bool primeFound = false;
        for(int test = primes[current] + 2; !primeFound; test += 2)
        {
            for(int p = 0; p <= current; p++)
            {
                primeFound = true;
                if(test % primes[p] == 0)
                {
                    primeFound = false;
                    break;
                }
            }
            if(primeFound)
            {
                primes[++current] = test;
            }
        }
        
        if(current == stop)
            running = false;
        
        return SUCCEEDED;
    }
    
    const SUCCESS display() const
    {
        std::cout<<primes[current]<<std::endl;
        return 0;
    }
    
    const SUCCESS load()
    {
        if(stop <= 2)
            return -1;
        
        if(primes)
            unload();
        
        primes = new int[stop];
        primes[0] = 2;
        primes[1] = 3;
        current = 1;
        
        return 0;
    }
    
    const SUCCESS unload()
    {
        if(primes)
            delete [] primes;
        
        primes = NULL;
        return 0;
    }
    
public:
    TestLoop(const int n): primes(NULL), stop(n) {};
    virtual ~TestLoop() {};
};

int main(int argc, char **argv)
{
    if(argc < 2)
    {
        std::cout<<"Call with number as first argument"<<std::endl;
        return 1;
    }
    
    TestLoop myGameLoop(atoi(argv[1]));
    return myGameLoop.run();
}










