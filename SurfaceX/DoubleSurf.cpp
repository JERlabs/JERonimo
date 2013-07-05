#include "DoubleSurf.h"

namespace SurfaceX {

void DoubleSurf::set(SDL_Surface * const s) {
  if(this->SafeSurf::get() == NULL) {
    this->SafeSurf::set(s);
    this->SimpleDummy::set(copy());
  }
  this->SimpleDummy::set(s);
}

SDL_Surface * const DoubleSurf::get() const {
  (const_cast<DoubleSurf *>(this))->SimpleDummy::set(copy());
  return this->SimpleDummy::get();
}

}