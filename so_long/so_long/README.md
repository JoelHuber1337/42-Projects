This is a Programm that creates a Window, hooks keyboard events, puts images on said Window and impliments movement.
So_Long is a Game, it's about a Character moving through a level, Collecting all Collectable and exiting the Game.
The terminal in which the Programm was executed in, keeps track of player movement.
The Programm is made to support any size of .ber files, as long as it is valid with the size of the screen. 
So_long uses the <mlx.h> library to hook Events like the mouse and keys. To initialize a window and to put pictures on the Screen.
The mlx library png->window unfortunately doesn't work as well as other options, so for all textures, xpm->window is used.
Map parcing is done with a flood check and other checks by turning the .ber input file into a two dimensional array.
As a Bonus, the exit changes texture and opens when all Collectables are collected.

The Syntax for this Programm is:
./so_long Insert_Map_Path.ber

///Future Updates
-Improve map parcing, making the logic behind it more cut and clear. 
-Sprite animations
-More sprites
-Next level?
///Future Futre Updates
-Menus?
-Enemies?
-Weapons?
-Story?
-Gameplay?
