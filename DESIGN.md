App
===

Description
-----------
- Base class for the game.
- Manages a list of all game objects using STL types
- Controls game loops. (event, game, etc.)
- Provides an SDL surface.
- Controls creation of game window

Constructor
-----------
- Initalizes SDL
- Initalizes main surface
- Loads XML?

Entity
======

Description
-----------
- A game element which can be drawn to the screen
- Must provide a static method that will iterate through either a list or array of itself and draw each entity to a surface
- Must provide a static method to iterate through a list/array of itself and preform physics (position changes)  on each object
- Must provide methods to get coordinates
- must provide initalization and quit methods

Constructor
-----------
- Do stuff, set inital coords, velocity, etc.

Methods
-------
Names not final
- getCoords(Vector) - Get coordinates of the object
- Vector setCoords() - Set coordinates
- Vector getVelocity() - Get velocity vector
- setVelocity(Vector) - 
### Static ###
- method to iterate through a list of itself and do physics for velocities


Vector
======

Description
------------
- An object which holds an X and Y component
- Must have the methods to set and get X, Y, Magnitude, and Direction
- Overloads operators + which returns a vector constructed with the X and Y  of two argument components added (+= will work as expected)
- Overloads operator - which returns a vector to the difference of two vectors (say to find the distance or angle between two entities)
- Overloads operator * (right hand operator is number) which returns a vector constructed with the X and Y components both multiplied by the parameter
- Overloads operator / which works similarly to operator *
- Used for holding object positions/velocities/etc.

Constructor
-----------
- take initial X, Y.
- take initial Magnitude and Direction (x and y will have to have different types from mag and dir



Methods
-------
- getX() - May be changed to just x()
- getY() - ""
- getMagnitude()
- getDirection()
