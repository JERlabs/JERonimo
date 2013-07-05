#include "SafeSurf.h"

namespace SurfaceX {

SDL_Surface * const SafeSurf::copy() const {
  if(this->SimpleSurf::get() == NULL)
    return NULL;
  return SDL_ConvertSurface(this->SimpleSurf::get(), this->SimpleSurf::get()->format, this->SimpleSurf::get()->flags);
}

void SafeSurf::set(SDL_Surface * const s) {
  SDL_Surface* handle;
  this->SimpleSurf::set(handle = SDL_ConvertSurface(s, s->format, s->flags));
}

}