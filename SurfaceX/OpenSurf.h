#ifndef _OPENSURF_H_
#define _OPENSURF_H_

#include "JustASurf.h"

namespace SurfaceX {

class OpenSurf: public JustASurf {
private:
  SDL_Surface *canvas;
  
public:
  /// Return the internal raw surface
  virtual SDL_Surface * const get() const {return canvas;};
  /// Set the internal raw surface to set
  virtual void set(SDL_Surface * const s);
  /// Return the internal raw surface
  operator SDL_Surface *() const {return get();};
  SDL_Surface *operator->() const {return get();};
  SDL_Surface *operator*() const {return get();};
  
public:
  /// Create a new OpenSurf with the internal surface set to NULL
  OpenSurf(): canvas(NULL) {};
  /// Create a new OpenSurf with the internal surface set to init
  OpenSurf(SDL_Surface * const init): canvas(init) {canvas==NULL? 0:canvas->refcount++;};
  OpenSurf(const OpenSurf& other): canvas(other.get()) {canvas==NULL? 0:canvas->refcount++;};
  /// Create a new OpenSurf with an image loaded from file
  OpenSurf(char * const file): JustASurf(file) {};
  /// Destroy this OpenSurf, frees the internal surface as well
  virtual ~OpenSurf();
};

}

#endif /*_OPENSURF_H_*/
