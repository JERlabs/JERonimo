#include "OpenSurf.h"

namespace SurfaceX {

OpenSurf::~OpenSurf() {
  SDL_FreeSurface(canvas);
  canvas = NULL;
}

}

/* Gosh what an empty file. Oh hello dev. Aren't you open source, 
 * looking at these .cpp's rather than consulting the documentation or even the .h's like any old chump would.
 * You're not part of their system.
 * Kudos to you.
 * 	-EdWard
 */