#ifndef _STATICSURF_H_
#define _STATICSURF_H_

#include "JustASurf.h"

namespace SurfaceX {

class StaticSurf: public JustASurf {
private:
  SDL_Surface *data;  ///< Data which, when initialized, remains unchanged and unaccessible except for drawing and copying.
  
private:  
  SDL_Surface * const Surf() const {return data;};
  SDL_Surface * const Surf(SDL_Surface * const d) {return data=d;};
  //operator SDL_Surface *() const {return copy();};
  //ommitted since there really isn't an implementation for this
  
public:
  SDL_Surface * const copy(); ///< Returns new Surface with all pixels of data copied over.
  
public:
  StaticSurf(): data(NULL) {};
  StaticSurf(SDL_Surface * const init) {
    data = SDL_ConvertSurface(init, init->format, init->flags);
  };
  
  explicit StaticSurf(const StaticSurf& other): data(other.data) {
    data->refcount++;
  };
  
  StaticSurf(char * const file): JustASurf(file) {};
  
  ~StaticSurf() {
    SDL_FreeSurface(data);
  };
  
};

}


#endif /*_STATICSURF_H_*/