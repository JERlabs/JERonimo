#ifndef _SAFESURF_H_
#define _SAFESURF_H_

#include "SimpleSurf.h"

namespace SurfaceX {

class SafeSurf: public SimpleSurf {
private:
  virtual operator SDL_Surface *() const {return get();};  	///< Implicit raw data (SDL_Surface) get access function.
  virtual SDL_Surface * const operator->() const {return get();};  	///< Implicit raw data member access function.
  virtual SDL_Surface * const operator*() const {return get();};	///< Explicit raw data access operator.

  virtual SDL_Surface * const get() const {return copy();};
  
public:
  virtual void set(SDL_Surface * const s);
  //operator SDL_Surface *() const {return copy();};
  //ommitted since there really isn't an implementation for this
  
public:
  SDL_Surface * const copy() const; ///< Returns new Surface with all pixels of data copied over.
  
public:
  SafeSurf(): SimpleSurf() {};
  
  SafeSurf(SDL_Surface * const init): SimpleSurf(SDL_ConvertSurface(init, init->format, init->flags), false) {};
  
  explicit SafeSurf(const SafeSurf& other): SimpleSurf(other) {};
  
  SafeSurf(char * const file): SimpleSurf(file) {};
  
  virtual ~SafeSurf() {};
  
};

}

#endif /*_SAFESURF_H_*/