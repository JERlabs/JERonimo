# Namespace Something #
Working title

## App ##
Main class which is called from the int main function of your code. Runs
a gameloop each tick which returns which game loop to run next tick. May
provide a user-defined data-sharing object. Provides some way of managing
game states

### Description ###
- Base class for the game.
- Manages a list of all game objects using STL types
- Runs a game loop, which returns the loop to run next tick. 
- Provides an SDL surface.
- Controls creation of game window
- Has a method to return a datamanaging object
- Keeps track of GameStates and GameLoops

### Constructor ###
- Initalizes SDL
- Initalizes main surface
- Takes a gameloop?
- Takes properties for SDL surface?
- Loads XML? -- the datamanager might do this

## GameLoop ##
Runs every tick. Return which GameLoop to run next.

### Description ###
- A class with a run function
- A loop that will be run each tick
- Will run every tick, returns the GameLoop to be run next tick

### Methods ###
- GameLoop run(short time) - runs the game loop, takes the time elapsed between game loops, in miliseconds

## Entity ##
This object will probably change purpose to be more flexible
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

# Namespace Space2D #

### Description ###
- Namespace containing position class and vector class
- Point and Vector are symmetrically compatible
- Contains velocity class.
- Contains functions which include both classes for certain compatibility.

## Point ##
Used for an ordered pair
### Description ###
- Class containing X and Y component
- X() and Y() return the values and X(number) Y(number) set them (return reference to this?)
- Operator + returns the sum of the X and Y components (vector addition essentially
- Operator - returns the difference of the X and Y components (for relative vector computation)
- Operators * and / scale position from (0, 0) at a factor of the right hand operator
- Overloads respective += -= *= and /=
- Overloads == and != as would be expected
- Constructed with X and Y (default 0)
- Constructed with Vector (calculates destination if origin is translated by Vector)

## Vector ##
Used when things need to point somewhere
### Description ###
- Class containing Magnitude and Direction
- Respective setter and getter functions
- Constructed with init magnitude and direction
- Constructed with a Point (calculates vector from origin to position)
- Default Constructor sets direction to 0 with mag of 0

## Velocity ##
Used when you need to point somewhere, and have easy access to coords
### Description ###
- Class which subclasses Vector and Point
- Allows the position of a vector relative to the origin to be stored,
  allowing for easy (computation-wise) access to position-updating methods

## Other Methods ##
- Position getPos(Vector) returns position of vector relative to origin
