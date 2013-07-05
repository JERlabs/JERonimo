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

class DoubleSurf: public SimpleDummy, private SafeSurf { 
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