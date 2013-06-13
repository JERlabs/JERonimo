# Namespace GameControl #

## App ##
Main class which is called from the int main function of your code. 
Pass it with a pointer to a DataManage, which will handle creation of the first GameLoop. 

### Description ###
- Inherites GameLoop for compatibility reasons.
- Start class for the game.
- Runs the first user defined GameLoop as specified in DataManager
- Provides an SDL display surface to DataManager.
- Initializes SDL and creates Game Window.
- On return of the first GameLoop's run, cleans up SDL and closes the window.

### Constructor ###
- Is passed with a pointer to the user defined DataManager (basic level DataManager)

### Methods ###

#### Runs ####
- Runs the GameLoop from the passed DataManager object.
- Passes itself to the GameLoop object

## GameLoop ##
Runs the GameLoop, inherits Events.

### Methods ###
- Constructed with GameLoop &
- Run(), runs init, then iterates through event polling, event handling, looping, and rendering. On completion, should run Cleanup. Run() is final! Not to be overloaded.
- Init(), loads objects in DataManager.
- handleEvents() [final], passes event details to functions which are overloaded by GameLoop children
- loop(), runs repeating functions on Data in the DM.
- render() [const], draws Data in the DM to the display surface. [const] so that it won't do any calculations.
- cleanup(), cleans up Data to be destroyed in the DM (such as Entity surfacess)

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


# Easter Eggs #
- huehuehuehuehue
