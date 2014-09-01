#include "SDLWrappers.h"

using namespace std;
using namespace jer;

int main(int argc, char **argv)
{
    DrawOverRenderer<HardRenderer> ren(shared_ptr<Window>(new Window("ScaledTextureTest",
                                                                         Point<int>(100, 100), Dimensions<int>(640, 480), 
                                                                         Window::SHOWN)), true, true);
    Surface surf(string("test.png"));
    ScaledSurface scaled(surf, Dimensions<int>(50, 50));
    Texture surfText(make_shared<Surface>(surf), &ren);
    Texture scaledText(make_shared<ScaledSurface>(scaled), &ren);
    if(surfText.load() < SUCCEEDED || scaledText.load() < SUCCEEDED)
    {
        cout<<"Texture failed to load"<<endl;
        return FAILED;
    }
    if(scaledText.blit(Point<int>(10, 10)))
    {
        cout<<"Scaled Texture failed to blit"<<endl;
        return FAILED;
    }
    if(surfText.blit(Point<int>(100, 100)))
    {
        cout<<"Regular Texture failed to blit"<<endl;
        return FAILED;
    }
    ren.display();
    SDL_Delay(2000);
    return 0;
}