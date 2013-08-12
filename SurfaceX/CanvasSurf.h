#ifndef _CANVASSURF_H_
#define _CANVASSURF_H_

#include "SimpleSurf.h"


class CanvasSurf: public virtual SimpleSurf {
private:
  Point zoom;
  Radians angle;
  
  
public:
  void rasterize();
  
  
}

#endif