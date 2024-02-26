# Text Adventure Glitch

## Build

Built using Qt Creator (Qt 6) using CMake and ninja on MacOS.

Note: On Microsoft Windows it may be necessary to add the following line or similar to the file CMakeLists.txt:

set(CMAKE_PREFIX_PATH "C:/Qt/6.4.0/msvc2019_64")

This will help the build system find the location of Qt and the Microsoft compiler, but it might not be needed if your Qt system is already fully configured.

## Usage

The application can be run from within Qt Creator.

Once runnning the player should type a command in the textbox to the right of the label "Enter command: ". This is at the bottom of the screen. 
e.g. Type "n" or "north" (all lower-case) and hit Enter.

Type "q" or "quit" and hit Enter to end the game and terminate the program.


## Future Improvements

1. Use a game map
    * The main improvement would be to use a proper map of the game world/environment so that all the rooms are interconnected in a defined way. 
    * Set up a structure with room details specifying where the n/e/s/w doors link to. Some directions may not be valid, e.g. a room may not have an east exit.
2. Expand room content
    * Increase the number of rooms and enhance their text content. 
    * Place objects in the rooms that can be collected and/or used.
3. Add commands
    * Add commands to allow the player to pick up items, use the items in other rooms (e.g. a key that opens a door or a chest which contains another item, e.g. gold.
4. Make the map content dynamic
    * Doors could have state: locked or unlocked, requiring a key to unlock the before the player can pass through the door. 
    * If the player picks up an item, moves room, and puts it down again, then the item will have moved rooms. So the map should be enhanced to make it dynamic, enabling the player to change which items are in which rooms. Each room would have a dynamic list of items. 
5. Add point scoring
    * Add the ability to score points: picking up items in room can increase your score, and then if the player can work out how to use the item, that can increase the score further.
6. Add 'Game Over' functionality 
    * If the player does something really bad, the game ends.
7. Add unique features
    * Add unique features to amuse the player. One idea was to add deliberate glitches to produce surprises for the player to make the experience more fun.
8. Add unit tests 
    * Unit tests will enable the code to be developed safely as the size of the code base expands.


