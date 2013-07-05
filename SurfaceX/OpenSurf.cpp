#include "OpenSurf.h"

namespace SurfaceX {

OpenSurf::~OpenSurf() {
  if(canvas != NULL)
    SDL_FreeSurface(canvas);
  canvas = NULL;
}

void OpenSurf::set(SDL_Surface * const s) {
  if(canvas != NULL)
    SDL_FreeSurface(canvas);
  canvas = s;
  if(s == NULL)
    canvas->refcount++;
}

}

/* Gosh what an empty file. Oh hello dev. Aren't you open source, 
 * looking at these .cpp's rather than consulting the documentation or even the .h's like any old chump would.
 * You're not part of their system.
 * Kudos to you.
 * 	-EdWard
 */