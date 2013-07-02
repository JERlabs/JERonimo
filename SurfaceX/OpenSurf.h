#ifndef _OPENSURF_H_
#define _OPENSURF_H_

#include "JustASurf.h"

namespace SurfaceX {

class OpenSurf: public JustASurf {
private:
  SDL_Surface *canvas;
  
public:
  virtual SDL_Surface * const Surf() const {return canvas;};
  virtual SDL_Surface * const Surf(SDL_Surface * const set) {return canvas = set;};
  virtual operator SDL_Surface *() const {return Surf();};
  virtual SDL_Surface *operator->() const {return canvas;};
  
public:
  OpenSurf(): canvas(NULL) {};
  OpenSurf(SDL_Surface * const init): canvas(init) {canvas->refcount++;};
  OpenSurf(char * const file): JustASurf(file) {};
  virtual ~OpenSurf();
};

}

#endif /*_OPENSURF_H_*/