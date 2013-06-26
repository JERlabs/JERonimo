#include "SurfaceX.h"

namespace SurfaceX {
  
class StaticSurf {
private:
  SDL_Surface *surf;
  
public:
  StaticSurf();
  StaticSurf(const StaticSurf&);
  StaticSurf(SDL_Surface *init);
  
  virtual const bool load(const char * const file);
  virtual const bool draw(SDL_Surface * const dest) const;
  
  virtual ~StaticSurf():
};
  
}