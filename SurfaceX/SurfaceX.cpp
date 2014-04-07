#include "SurfaceX.h"

namespace jer {
/*
SDL_Surface * const loadSurf(const char * const file) {
  SDL_Surface *temp =  NULL, *ret = NULL;
  
  if((temp = IMG_Load(file)) == NULL)
    return NULL;
  
  ret = SDL_DisplayFormatAlpha(temp);
  SDL_FreeSurface(temp);
  
  return ret;
}

const bool drawSurf(SDL_Surface * const src, SDL_Surface * const dest, const SDL_Rect &srcRect, const SDL_Rect &destRect) {
  if(src == NULL || dest == NULL)
    return false;
  
  if(!SDL_BlitSurface(src, &srcRect, dest, &destRect))
    return false;
  
  return true;
}

const bool drawSurf(SDL_Surface * const src, SDL_Surface * const dest, const Space2D::Point destPoint) {
  if(src == NULL || dest == NULL)
    return false;
  
  SDL_Rect destRect;
  destRect.x = destPoint.x();
  destRect.y = destPoint.y();
  
  if(!SDL_BlitSurface(src, NULL, dest, &destRect))
    return false;
  
  return true; 
}

*/

const bool transparentSurf(SDL_Surface * const surf, const Uint8 R, const Uint8 G, const Uint8 B) {
  if(surf == NULL)
    return false;
    
  if(SDL_SetColorKey(surf, SDL_SRCCOLORKEY | SDL_RLEACCEL, SDL_MapRGB(surf->format, R, G, B)))
    return false;
  
  return true;  
}

/*
SDL_Surface * const resizeSurf(SDL_Surface * const surf, const double scale, const bool smooth) {
  if(surf == NULL)
    return NULL;	
  
  return zoomSurface(surf, scale, scale, smooth? SMOOTHING_ON:SMOOTHING_OFF);
}

SDL_Surface * const resizeSurf(SDL_Surface * const surf, const double scaleX, const double scaleY, const bool smooth) {
  if(surf == NULL)
    return NULL;
  
  return zoomSurface(surf, scaleX, scaleY, smooth? SMOOTHING_ON:SMOOTHING_OFF);
}

SDL_Surface * const resizeSurf(SDL_Surface * const surf, const Space2D::Point &scaleXY, const bool smooth) {
  if(surf == NULL)
    return NULL;
  
  return zoomSurface(surf, scaleXY.x(), scaleXY.y(), smooth? SMOOTHING_ON:SMOOTHING_ON);
}

SDL_Surace * const rotateSurf(SDL_Surface * const surf, const double angle, const bool smooth) {
  if(surf == NULL)
    return NULL;
  
  return rotozoomSurface(surf, angle, 1, smooth? SMOOTHING_ON:SMOOTHING_OFF);
}

SDL_Surface * const rotateSurf(SDL_Surface * const surf, const Space2D::Vector &change, const bool smooth) {
  if(surf == NULL)
    return NULL;
  
  return rotozoomSurface(surf, change.theta(), change.magnitude(), smooth? SMOOTHING_ON:SMOOTHING_OFF);
}
*/


}