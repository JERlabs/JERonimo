#ifndef _DOUBLESURF_H_
#define _DOUBLESURF_H_

#include "SafeSurf.h"

namespace SurfaceX {

class SimpleDummy: public SimpleSurf {
public:
  SimpleDummy(): SimpleSurf() {};
  SimpleDummy(SDL_Surface * const init): SimpleSurf(init, false) {};
  SimpleDummy(const SimpleDummy &other): SimpleSurf(other) {};
  SimpleDummy(char * const file): SimpleSurf(file) {};
  
 // virtual void set(SDL_Surface * const s);
  
  virtual ~SimpleDummy()=0;
};

SimpleDummy::~SimpleDummy() {};

/*void SimpleDummy::set(SDL_Surface * const s) {
  this->SimpleSurf::set(s);
  s->refcount--;
}
*/

class DoubleSurf: public SimpleDummy, public SafeSurf { 
public:
  //using SafeSurf::load;
  const int load(char * const file);
  //using SimpleDummy::draw;
  const int draw(SDL_Surface * const dest, const Space2D::Point &p) const {return this->SimpleDummy::draw(dest, p);};
  const int draw(SDL_Surface * const dest, SDL_Rect &srcRect, SDL_Rect &destRect) const {
    return this->SimpleDummy::draw(dest, srcRect, destRect);
  };
  operator SDL_Surface *() const {return get();};
  SDL_Surface * const operator->() const {return get();};
  SDL_Surface * const operator*() const {return get();};
  const bool operator== (SDL_Surface * const other) const {return this->SimpleDummy::operator==(other);};
  const bool operator!= (SDL_Surface * const other) const {return !(*this == other);};
  
public:
  virtual void set(SDL_Surface * const s);
  virtual SDL_Surface * const get() const;
  
public:
  DoubleSurf(): SafeSurf(), SimpleDummy() {};
  DoubleSurf(SDL_Surface * const init): SafeSurf(init) {this->SimpleDummy::set(copy());};
  DoubleSurf(const DoubleSurf& other): SafeSurf(other) {this->SimpleDummy::set(copy());};
  DoubleSurf(char * const file): SafeSurf(file) {this->SimpleDummy::set(copy());};
  ~DoubleSurf() {};
};

}




#endif /*_DOUBLESURF_H_*/