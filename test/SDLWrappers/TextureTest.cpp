#include "SDLWrappers.h"

using namespace std;
using namespace jer;

int main(int argc, char **argv)
{
    DrawOverRenderer<HardRenderer> ren(shared_ptr<Window>(new Window("TextureTest",
                                                                         Point<int>(100, 100), Dimensions<int>(640, 480), 
                                                                         Window::SHOWN)), true, true);
    Texture testText(string("test.png"), &ren);
    if(testText.load() < SUCCEEDED)
    {
        std::cout<<"Texture failed to load"<<std::endl;
        return FAILED;
    }
    testText.blit(Point<int>(10, 10));
    ren.display();
    SDL_Delay(2000);
    return 0;
}