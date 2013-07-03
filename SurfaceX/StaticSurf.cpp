#include "StaticSurf.h"

namespace SurfaceX {

SDL_Surface * const StaticSurf::copy() {
    return SDL_ConvertSurface(data, data->format, data->flags);
  };
}