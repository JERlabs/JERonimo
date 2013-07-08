#include "SafeSurf.h"

namespace SurfaceX {

void SafeSurf::set(SDL_Surface * const s) {
  SDL_Surface* handle;
  this->SimpleSurf::set(handle = SDL_ConvertSurface(s, s->format, s->flags));
}

}