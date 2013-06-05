App
===

Description
-----------
Base class for the game.
Manages a list of all game objects using STL types
Controls game loops. (event, game, etc.)
Provides an SDL surface.
Controls creation of game window


Entity
======

Description
-----------
A game element which can be drawn to the screen
Must provide a static method that will iterate through either a list or array of itself and draw each entity to a surface
Must provide a static method to iterate through a list/array of itself and preform physics (position changes)  on each object
Must provide methods to get coordinates
must provide initalization and quit methods

