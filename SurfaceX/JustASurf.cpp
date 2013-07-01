#include "JustASurf.h"

namespace SurfaceX {
  
JustASurf::JustASurf(char * const file) {
  if(!load(file))
    cout<<"Failed to load "<<file<<endl<<"Personally, I blame you"<<endl;
}

const bool JustASurf::load(char * const file) {
  SDL_Surface *temp = NULL, *rslt;
  
  if(Surf() != NULL)
    SDL_FreeSurface(Surf());
  
  if((temp = IMG_Load(file)) == NULL)
    return false;

  Surf(rslt = SDL_DisplayFormatAlpha(temp));
  if(rslt == NULL) {
    SDL_FreeSurface(temp);
    return false;
  }
  
  SDL_FreeSurface(temp);
  return true;
}

const bool JustASurf::draw(SDL_Surface * const dest, SDL_Rect &srcRect, SDL_Rect &destRect) const {
  if(Surf() == NULL || dest == NULL)
    return false;
  
  if(SDL_BlitSurface(Surf(), &srcRect, dest, &destRect))
    return false;
  
  return true;
}

const bool JustASurf::draw(SDL_Surface * const dest, const Space2D::Point &p) const {
  SDL_Rect destRect = {p.x(), p.y(), Surf()->w, Surf()->h};
  
  if(SDL_BlitSurface(Surf(), NULL, dest, &destRect))
    return false;
  
  return true;
}


}