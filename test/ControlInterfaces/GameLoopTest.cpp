#include "ControlInterfaces.h"
#include <iostream>
#include <cstdlib>

using namespace jer;

class PrimeGeneratorLoop: public GameLoop
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
        
        if(current+1 == stop)
            running = false;
        
        return SUCCEEDED;
    }
    
    const SUCCESS display() const
    {
        if(current == 2)
        {
            std::cout<<primes[0]<<std::endl;
            std::cout<<primes[1]<<std::endl;
        }
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
    PrimeGeneratorLoop(const int n): primes(NULL), stop(n) {};
    virtual ~PrimeGeneratorLoop() {};
};

class FibGeneratorLoop: public GameLoop
{
    int *fibs;
    int current;
    int stop;
    
protected:
    const SUCCESS loop()
    {
        current++;
        fibs[current] = fibs[current-1] + fibs[current - 2];
        if(current+1 == stop)
            running = false;
        
        return SUCCEEDED;
    }
    
    const SUCCESS display() const
    {
        if(current == 2)
        {
            std::cout<<fibs[0]<<std::endl;
            std::cout<<fibs[1]<<std::endl;
        }
        std::cout<<fibs[current]<<std::endl;
        return 0;
    }
    
    const SUCCESS load()
    {
        if(stop <= 2)
            return -1;
        
        if(fibs)
            unload();
        
        fibs = new int[stop];
        fibs[0] = 1;
        fibs[1] = 1;
        current = 1;
        
        return 0;
    }
    
    const SUCCESS unload()
    {
        if(fibs)
            delete [] fibs;
        
        fibs = NULL;
        return 0;
    }
    
public:
    FibGeneratorLoop(const int n): fibs(NULL), stop(n) {};
    virtual ~FibGeneratorLoop() {};
};

int main(int argc, char **argv)
{
    if(argc < 3)
    {
        std::cout<<"Call with number [p or f] as first argument and number as second argument"<<std::endl;
        return 1;
    }
    
    GameLoop *generator = NULL;
    
    if(argv[1][0] == 'f')
        generator = new FibGeneratorLoop(atoi(argv[2]));
    else if(argv[1][0] == 'p')
        generator = new PrimeGeneratorLoop(atoi(argv[2]));
    else
    {
        std::cout<<"First arg should be either f (fibinnaci) or p (prime)"<<std::endl;
        return 1;
    }
    
    return generator->run();
}










