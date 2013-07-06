#include "SimpleSurf.h"

namespace SurfaceX {
  
SimpleSurf::SimpleSurf(char * const file) {
  if(load(file))
    cout<<"Failed to load "<<file<<endl<<"Personally, I blame you"<<endl;
}

void SimpleSurf::set(SDL_Surface * const s) {
  if(s == Surf)
    return;
  if(Surf != NULL)
    SDL_FreeSurface(Surf);
  Surf = s;
  //Surf->refcount++;
}

const int SimpleSurf::load(char * const file) {
  SDL_Surface *temp = NULL, *rslt = NULL;
  
  if(file == NULL)
    return -1;
  
  if((temp = IMG_Load(file)) == NULL)
    return -1;

  rslt = SDL_DisplayFormatAlpha(temp);
  if(rslt == NULL) {
    SDL_FreeSurface(temp);
    return -1;
  }
  
  if(Surf != NULL) {
    SDL_FreeSurface(Surf);
    Surf == NULL;
  }
  
  Surf = rslt;
  
  SDL_FreeSurface(temp);
  return 0;
}

const int SimpleSurf::draw(SDL_Surface * const dest, SDL_Rect &srcRect, SDL_Rect &destRect) const {
  if(getToDraw() == NULL || dest == NULL)
    return -1;
  
  if(SDL_BlitSurface(getToDraw(), &srcRect, dest, &destRect))
    return -1;
  
  return 0;
}

const int SimpleSurf::draw(SDL_Surface * const dest, const Space2D::Point &p) const {
  if(getToDraw() == NULL || dest == NULL)
    return -1;
  
  SDL_Rect destRect = {p.x(), p.y(), getToDraw()->w, getToDraw()->h};
  
  if(SDL_BlitSurface(getToDraw(), NULL, dest, &destRect))
    return -1;
  
  return 0;
}

SimpleSurf::~SimpleSurf() {
  if(Surf != NULL)
    SDL_FreeSurface(Surf);
  Surf = NULL;
}


}