#include "SDLWrappers.h"

using namespace std;
using namespace jer;

int main(int argc, char **argv)
{
    DrawOverRenderer<HardRenderer> ren(shared_ptr<Window>(new Window("ScaledTextureTest",
                                                                         Point<int>(100, 100), Dimensions<int>(640, 480), 
                                                                         Window::SHOWN)), true, true);
    ScaledTexture testText(Texture(string("test.png"), &ren), Dimensions<int>(50, 50));
    if(testText.load() < SUCCEEDED)
    {
        cout<<"Texture failed to load"<<endl;
        return FAILED;
    }
    testText.blit(Point<int>(10, 10));
    ren.display();
    SDL_Delay(2000);
    return 0;
}