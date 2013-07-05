#ifndef _SIMPLESURF_H_
#define _SIMPLESURF_H_

#include "SurfaceX.h"

namespace SurfaceX {

/// Uses abstract raw data get functions to get the SDL_Surfaces present child classes.
class SimpleSurf {
private:
  SDL_Surface *Surf;  ///< The data.
  
public:
  virtual SDL_Surface * const get() const {return Surf;};	///< Explicit raw data (SDL_Surface) get access function.
  virtual void set(SDL_Surface * const s);  ///< Explicit raw data (SDL_Surface) set access function.
  operator SDL_Surface *() const {return get();};  	///< Implicit raw data (SDL_Surface) get access function.
  SDL_Surface * const operator->() const {return get();};  	///< Implicit raw data member access function.
  SDL_Surface * const operator*() const {return get();};	///< Explicit raw data access operator.
  
public:
  virtual const int load(char * const file); ///< Loads image passed by file. Returns false on failure. Sets Surf to NULL.
  
private:
  virtual SDL_Surface * const getToDraw() const {return Surf;};  ///< Function that is only called by draw. Allows specification of internal memory transfer.

public:
  const int draw(SDL_Surface * const dest, const Space2D::Point &p) const; ///< Blits Surf to dest at p.
  const int draw(SDL_Surface * const dest, SDL_Rect &srcRect, SDL_Rect &destRect) const; ///< Blits Surf to dest bounded by srcRect and destRect.
  
public:
  
  /// Default constructor, behavior determined by subclasses
  SimpleSurf(): Surf(NULL) {};
  
  /// Initialization constructor. Doesn't increment reference count if second argument is false.
  SimpleSurf(SDL_Surface * const init, const bool ref): Surf(init) {ref && init? Surf->refcount++:0;};
  
  /// Copy Constructor
  SimpleSurf(const SimpleSurf &other): Surf(other.Surf) {Surf? Surf->refcount++:0;};
  
  /// Loads image from file into a new object
  SimpleSurf(char * const file);
  
  /// Frees Surface.
  virtual ~SimpleSurf();
  
};


}

#endif /*_SIMPLESURF_H_*/