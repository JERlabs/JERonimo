#ifndef _CANVASSURF_H_
#define _CANVASSURF_H_

/*#include "SimpleSurf.h"

namespace jer {

  class CanvasSurf: public virtual SimpleSurf {
  private:
    Point zoom;
    Radians angle;
    
  public:
    void stretch(const Point& z);
    void sotate(const Radians &r);
    const Point &getZoom() const;
    const Radians &getAngle() const;
    
  public:
    CanvasSurf(): SimpleSurf(NULL, false), zoom(0.0, 0.0), angle(0.0) {};
    CanvasSurf(SDL_Surface * const init, const Point &z, const Radians &rot, const bool ref);
    CanvasSurf(const CanvasSurf &other): SimpleSurf(other), zoom(other.zoom), angle(other.angle) {};
    CanvasSurf &operator= (const CanvasSurf& other);
    virtual ~CanvasSurf();
  };

}
*/
#endif