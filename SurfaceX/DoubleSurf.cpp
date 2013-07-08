#include "DoubleSurf.h"

namespace SurfaceX {

void DoubleSurf::set(SDL_Surface * const s) {
  if(original == NULL) {
    original.set(s);
    SimpleSurf::set(original.copy());
    return;
  }
  SimpleSurf::set(s);
}

SDL_Surface * const DoubleSurf::get() const {
  //if(refresh) {
  (const_cast<DoubleSurf *>(this))->SimpleSurf::set(original.copy());
  //refresh = false;
  //}
  return SimpleSurf::get();
}

/*
SDL_Surface * const DoubleSurf::getToDraw() const {
  //refresh = true;
  return SimpleSurf::getToDraw();
}
*/

const int DoubleSurf::load(char * const file) {
  const int rtrn = original.load(file);
  if(rtrn)
    return rtrn;
  SimpleSurf::set(original.copy());
  return 0;
}

}