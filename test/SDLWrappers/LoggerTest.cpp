#include <stdlib.h>
#include "SDLWrappers.h"

using namespace jer;
using namespace std;

class TestLogger: public SimpleProcess
{
private:
    int count;
    
public:
    virtual const SUCCESS load() override
    {
        cout<<"Initializing count to 0"<<endl;
        count = 0;
        return SUCCEEDED;
    };
    
    virtual const SUCCESS unload() override
    {
        cout<<"Finishing with a count of "<<count<<endl;
        return SUCCEEDED;
    };
    
    virtual const SUCCESS loop() override
    {
        cout<<"Looping"<<endl;
        count++;
        if(count == 5)
        {
            cout<<"Loading a surface"<<endl;
            SDL_Surface *surf = SDL_LoadBMP("test.bmp");
            if(surf == NULL)
                return FAILED;
            SDL_FreeSurface(surf);
        }
        if(count == 7)
        {
            cout<<"7 is failure"<<endl;
            return FAILED;
        }
        if(count > 10)
            stop();
        return SUCCEEDED;
    };
    
    virtual const SUCCESS display() const override
    {
        cout<<"Displaying count: "<<count<<endl;
        return SUCCEEDED;
    };
};

int main(int argc, char **argv)
{
    Logger<TestLogger> logger;
    App::GetApp().setApp(&logger);
    App::GetApp().initAll();
    return App::GetApp().run();
}