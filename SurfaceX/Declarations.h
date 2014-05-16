#ifndef _SURFACEX_H_
#define _SURFACEX_H_

#include <stdlib.h>
#include <iostream>

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_rotozoom.h"

#include "Space2D.h"

/** Namespace which has container classes used to manipulate surfaces and handle
 * their spaces in memory. Also contains static functions used without container class
 * to perform same function.
 */
namespace jer {
  
/// Abstract surface interface. (load and draw). No actual memory for surface. 
class SimpleSurf;
/*
class OpenSurf;  //Part of the free surface movement. Keep images OpenSurf. JK, only do that if you know what you're doing
/// Inherits SimpleSurf. Allows implicit surface conversion to SDL_Surface *. 
*/

/// Inherits SimpleSurf. Remains read(draw)-only after initialization.
class SafeSurf;

/// Inherits SimpleSurf and has a SafeSurf. Essentially keeps track of original surface through SafeSurf, and uses SimpleSurf to manipulate.
class DoubleSurf;

/// Inherits SimpleSurf. Equipped with transformation functions and data members which keep track of transformations.
class CanvasSurf;

/// Inherits CanvasSurf and DoubleSurf.
class SuperSurf;


const bool transparentSurf(SDL_Surface * const surf, const Uint8 R, const Uint8 G, const Uint8 B);

/*
/** Allows for quick incrementing of refcount for surfaces.*
SDL_Surface &operator++ (SDL_Surface &surf) {return ++surf.refcount;};
SDL_Surface &operator++ (SDL_Surface &surf, int a) {return surf.refcount++;};
SDL_Surface &operator-- (SDL_Surface &surf) {return --surf.refcount;};
SDL_Surface &operator-- (SDL_Surface &surf, inta ) {return surf.refcount--;};
*/

/*
/// Loads file and returns surface. returns NULL on failure
SDL_Surface * const loadSurf(char * const file);

/// Draws the srcRect portion of src to the destRec portion of dest
const bool drawSurf(SDL_Surface * const src, SDL_Surface * const dest, const SDL_Rect &srcRect, const SDL_Rect &destRect);

/// Same as other drawSurf but draws entire src to dest at point destPoint
const bool drawSurf(SDL_Surface * const src, SDL_Surface * const dest, const Space2D::Point destPoint);

/// Makes every pixel of the color RGB in the surface surf transparent
const bool transparentSurf(SDL_Surface * const surf, const Uint8 R, const Uint8 G, const Uint8 B);

/// Creates a new surface from surf scaled by scale. If smooth is true, and the surface is 32-bit, the destination surface will be anti-aliased
SDL_Surface * const resizeSurf(SDL_Surface * const surf, const double scale, const bool smooth);

/// Creates a new surface from surf scaled by scaleX in the x direction and by scaleY in the Y direction.
SDL_Surface * const resizeSurf(SDL_Surface * const surf, const double scaleX, const double scaleY, const bool smooth);

/// Acts like resizeSurf but the scale is made up of the X and Y components of Point &scaleXY.
SDL_Surface * const resizeSurf(SDL_Surface * const surf, const Space2D::Point &scaleXY, const bool smooth);

/// Creates a new surface from surf rotated by angle (radians). See resizeSurf for smooth.
SDL_Surface * const rotateSurf(SDL_Surface * const surf, const double angle, const bool smooth);

/// Acts like rotateSurf and scaleSurf. Rotates surf by change.Theta() and scales both X and Y by change.Magnitude().  
SDL_Surface * const rotateSurf(SDL_Surface * const surf, const Space2D::Vector &change, const bool smooth);

*/

}

#endif /*_SURFACEX_H_*/
