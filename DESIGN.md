# Namespace Something #
Working title

## App ##

### Description ###
- Base class for the game.
- Manages a list of all game objects using STL types
- Controls game loops. (event, game, etc.)
- Provides an SDL surface.
- Controls creation of game window

### Constructor ###
- Initalizes SDL
- Initalizes main surface
- Loads XML?

## Entity ##

### Description ###
- A game element which can be drawn to the screen
- Must provide a static method that will iterate through either a list or array of itself and draw each entity to a surface
- Must provide a static method to iterate through a list/array of itself and preform physics (position changes)  on each object
- Must provide methods to get coordinates
- must provide initalization and quit methods

### Constructor ###
- Do stuff, set inital coords, velocity, etc.

### Methods ###
Names not final
- Position getCoords() - Get coordinates of the object
- setCoords(Position) - Set coordinates
- Vector getVelocity() - Get velocity vector
- setVelocity(Vector) - Set velocity vector

#### Static ####
- method to iterate through a list of itself and do physics for velocities

# Namespace Space #

### Description ###
- Namespace containing postion class and vector class
- Contains velocity class.
- Contains functions which include both classes for certain compatibility.

## Position ##
- Class containing X and Y component
- X() and Y() return the values and X(number) Y(number) set them (return reference to this?)
- Operator + returns the sum of the X and Y components (vector addition essentially
- Operator - returns the difference of the X and Y components (for relative vector computation)
- Operators * and / scale position from (0, 0) at a factor of the right hand operator
- Overloads respective += -= *= and /=
- Constructed with X and Y (default 0)

## Vector ##
- Class containing Magnitude and Direction
- Respective setter and getter functions
- Constructed with init magnitude and direction
- Constructed with a position (calculates vector from origin to position)
- Constructed with two positions (calculates vector from one to the other)
- Default Constructor sets direction to 0 with mag of 0

## Velocity ##
- Class which subclasses Vector and Position
- Allows the position of a vector relative to the origin to be stored,
  allowing for easy (computation-wise) access to position-updating methods

## Other Methods ##
- Position getPos(Vector) returns position of vector relative to origin
