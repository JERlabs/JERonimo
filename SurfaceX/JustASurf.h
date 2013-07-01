#ifndef _JUSTASURF_H_
#define _JUSTASURF_H_

#include "SurfaceX.h"

namespace SurfaceX {

class JustASurf {
/// Uses abstract raw data get functions to get the SDL_Surfaces present child classes.

public:
  virtual SDL_Surface * const Surf() const=0;	///< Explicit raw data (SDL_Surface) get access function.
  virtual SDL_Surface * const Surf(SDL_Surface * const set)=0;  ///< Explicit raw data (SDL_Surface) set access function.
  virtual operator SDL_Surface *() const=0;	///< Implicit conversion to raw data function.
  
public:
  const bool load(char * const file); ///< Loads image passed by file. Returns false on failure. Sets Surf to NULL.
  
  const bool draw(SDL_Surface * const dest, const Space2D::Point &p) const; ///< Blits Surf to dest at p.
  const bool draw(SDL_Surface * const dest, SDL_Rect &srcRect, SDL_Rect &destRect) const; ///< Blits Surf to dest bounded by srcRect and destRect.
  
public:
  JustASurf(char * const file);
  JustASurf() {};
  
};


}

#endif