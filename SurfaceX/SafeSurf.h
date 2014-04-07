#ifndef _SAFESURF_H_
#define _SAFESURF_H_

#include "SimpleSurf.h"

namespace jer {

class SafeSurf: public SimpleSurf {
public:
  operator const SDL_Surface *() const {return getToDraw();};  	///< Implicit raw data (SDL_Surface) get access function.
  const SDL_Surface * const operator->() const {return getToDraw();};  	///< Implicit raw data member access function.
  const SDL_Surface * const operator*() const {return getToDraw();};	///< Explicit raw data access operator.

  virtual SDL_Surface * const get() const {return copy();};
  
public:
  virtual void set(SDL_Surface * const s);
  //operator SDL_Surface *() const {return copy();};
  //ommitted since there really isn't an implementation for this
  
public:
  SafeSurf(): SimpleSurf() {};
  
  SafeSurf(SDL_Surface * const init): SimpleSurf(SDL_ConvertSurface(init, init->format, init->flags), false) {};
  
  explicit SafeSurf(const SafeSurf& other): SimpleSurf(other) {};
  
  //SafeSurf(char * const file): SimpleSurf(file) {};
  
  virtual ~SafeSurf() {};
  
};

}

#endif /*_SAFESURF_H_*/