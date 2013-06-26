#include "SurfaceX.h"

namespace SurfaceX {

class VolatileSurf: public StaticSurf {
private:
  SDL_Surface *out;
  Space2D::Point curScale;
  double curAngle;
  
public:
  VolatileSurf();
  VolatileSurf(const VolatileSurf &);
  VolatileSurf(const char * const file);
  
  virtual const bool draw(SDL_Surface *dest) const;
  
  const bool resize(const double scale, const bool smooth); ///< see SurfaceX
  const bool resize(const double scaleX, const double scaleY, const bool smooth); ///< see SurfaceX
  const bool resize(const Space2D::Point& scale, const bool smooth); ///< see SurfaceX
  const bool rotate(const double angle /*radians*/, const bool smooth); ///< see SurfaceX
  const bool rotate(const Space2D::Vector& change, const bool smooth); ///< see SurfaceX
  
  ~VolatileSurf();
  
};


}