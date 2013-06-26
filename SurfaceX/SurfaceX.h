#ifndef _SURFACEX_H_
#define _SURFACEX_H_

#include "SDL/SDL.h"
#include "SDL/SDL_Image.h"
#include "SDL/SDL_gfx"

#include "Space2D/Velocity.h"

namespace SurfaceX {
/** Namespace which has container classes used to manipulate surfaces and handle
 * their spaces in memory. Also contains static functions used without container class
 * to perform same function.
 */

class StaticSurf;	///< Container class for SDL_Surfaces, handles creation and destruction
class VolatileSurf;	///< Surface which handles scaling and rotating surfaces

SDL_Surface * const loadSurf(const char * const file);
/// Loads file and returns surface. returns NULL on failure

const bool drawSurf(SDL_Surface * const src, SDL_Surface * const dest, const SDL_Rect &srcRect, const SDL_Rect &destRect);
/// Draws the srcRect portion of src to the destRec portion of dest

const bool transparentSurf(SDL_Surface * const surf, const Uint8 R, const Uint8 G, const Uint8 B);
/// Makes every pixel of the color RGB in the surface surf transparent

SDL_Surface * const resizeSurf(SDL_Surface * const surf, const double scale, const bool smooth);
/// Creates a new surface from surf scaled by scale. If smooth is true, and the surface is 32-bit, the destination surface will be anti-aliased

SDL_Surface * const resizeSurf(SDL_Surface * const surf, const double scaleX, const double scaleY, const bool smooth);
/// Creates a new surface from surf scaled by scaleX in the x direction and by scaleY in the Y direction.

SDL_Surface * const resizeSurf(SDL_Surface * const surf, const Space2D::Point &scaleXY, const bool smooth);
/// Acts like resizeSurf but the scale is made up of the X and Y components of Point &scaleXY.

SDL_Surface * const rotateSurf(SDL_Surface * const surf, const double angle, const bool smooth);
/// Creates a new surface from surf rotated by angle (radians). See resizeSurf for smooth.

SDL_Surface * const rotateSurf(SDL_Surface * const surf, const Space2D::Vector &change, const bool smooth);
/// Acts like rotateSurf and scaleSurf. Rotates surf by change.Theta() and scales both X and Y by change.Magnitude().  


  
}





#endif /*_SURFACEX_H_*/