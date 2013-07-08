#ifndef _DOUBLESURF_H_
#define _DOUBLESURF_H_

#include "SafeSurf.h"

namespace SurfaceX {

class DoubleSurf: public SimpleSurf { 
private:
  SafeSurf original;
//  mutable bool refresh;
  
public:
  //using SafeSurf::load;
  virtual const int load(char * const file);
  //using SimpleSurf::draw;
protected:
  //virtual SDL_Surface * const getToDraw() const;
public:
  virtual void set(SDL_Surface * const s);
  virtual SDL_Surface * const get() const;
  
public:
  DoubleSurf(): original(), SimpleSurf() {};
  DoubleSurf(SDL_Surface * const init): original(init) {this->SimpleSurf::set(original.copy());};
  DoubleSurf(const DoubleSurf& other): original(other) {this->SimpleSurf::set(original.copy());};
  //DoubleSurf(char * const file): original(file), refresh(true) {this->SimpleSurf::set(original.copy());};
  virtual ~DoubleSurf() {};
};

}




#endif /*_DOUBLESURF_H_*/