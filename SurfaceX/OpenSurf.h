#ifndef _OPENSURF_H_
#define _OPENSURF_H_

#include "JustASurf.h"

namespace SurfaceX {

class OpenSurf: public JustASurf {
private:
  SDL_Surface *canvas;
  
public:
<<<<<<< HEAD
  /// Return the internal raw surface
  SDL_Surface * const Surf() const {return canvas;};
  /// Set the internal raw surface to set
  SDL_Surface * const Surf(SDL_Surface * const set) {return canvas = set;};
  /// Return the internal raw surface
  operator SDL_Surface *() const {return canvas;};
  SDL_Surface *operator->() const {return canvas;};
=======
  /// Return the internal raw surface
  virtual SDL_Surface * const Surf() const {return canvas;};
  /// Set the internal raw surface to set
  virtual SDL_Surface * const Surf(SDL_Surface * const set) {return canvas = set;};
  /// Return the internal raw surface
  virtual operator SDL_Surface *() const {return Surf();};
  virtual SDL_Surface *operator->() const {return canvas;};
>>>>>>> 5e63aa426c06a97e75c65ea1e7d6eeb267f40efd
  
public:
  /// Create a new OpenSurf with the internal surface set to NULL
  OpenSurf(): canvas(NULL) {};
  /// Create a new OpenSurf with the internal surface set to init
  OpenSurf(SDL_Surface * const init): canvas(init) {canvas->refcount++;};
  /// Create a new OpenSurf with an image loaded from file
  OpenSurf(char * const file): JustASurf(file) {};
  /// Destroy this OpenSurf, frees the internal surface as well
  virtual ~OpenSurf();
};

}

#endif /*_OPENSURF_H_*/
