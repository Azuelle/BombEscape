# BombEscape
*— a game made for ENGG1340 group project*

## Team Members

| **Name**     | **UID**      | **GitHub Username**                                           |
| :----------- | :----------- | :------------------------------------------------------------ |
| ***REMOVED*** | ***REMOVED*** | [@Azuelle](https://github.com/Azuelle)                        | 
| ***REMOVED*** | ***REMOVED*** | [@kxwhiowo](https://github.com/kxwhiowo)                      |
| ***REMOVED*** | ***REMOVED*** | [@qinchonghanzuibang](https://github.com/qinchonghanzuibang)  |
| ***REMOVED*** | ***REMOVED*** | [@Zhao-Shuman](https://github.com/Zhao-Shuman)                |
| ***REMOVED*** | ***REMOVED*** | [@Summerflyfly](https://github.com/Summerflyfly)              |

## Game Introduction
**BombEscape** is an uncompromising roguelike game. You will play as Marvolo, a rapacious wizard who overstudied dark magic and is now imprisoned in an unknown dungeon. In order to survive, Marvolo has to familiarize himself quickly with a randomly-generated environment that contains dangers including bombs and traps. 

Enter a chaotic world full of pitfalls and bombshells. Try your best to gather resources scattered in this world to arm yourself. Good luck to your survival journey. Play your way as you unravel the mysteries of this strange dungeon.

### Gameplay
- Marvolo must stay clear of the traps and bombs that are generated at random in the dungeon. If he gets in the range of explosion, he dies unless he has an item that protects him.
- Marvolo can destroy the traps by explosion either by placing a bomb himself or pushing those ones dropped into the dungeon close to the bomb. 
- Marvolo can gain new abilities by picking up items in the dungeon.
- The longer Marvolo survives, the higher the score. 

## Features & Explanation

### Random map generation
The map for the game is randomly generated to ensure a unique experience.

On the coding side, we organized the map generation utilites, the map class (`Playfield`) itself and map rendering utilities into different files to limit bloating of a single file.

### Restarting
You can retry the game after you have died. In detail, returning to the main menu resets the `GameState` object which contains your current status in the game, including your character (`Player`), the map (`Playfield`), and entities (stored with `std::vector<Entity*>`, a dynamic list of pointers, in `Playfield`).

### Controls
The player can use the keyboard to control Marvolo.

You can also change the key bindings by editing the `config.txt` file, which will be generated the first time you start the game. The key values are stored as their decimal ASCII codes.

#### Default key bindings
- `↑` / `←` / `↓` / `→` to move Marvolo
- `space` to place a bomb in front of Marvolo
- `enter` to confirm selection

## Dependencies
The following non-standard C/C++ library has been used in this project:
- `curses.h`/`ncurses.h` , for acquiring user input without blocking the processing and rendering the UI and graphics
- `unistd.h` , for using Linux utilities

## Quick Start

### Compilation
Run `make` under the root directory of the project (i.e. where this file is located) to compile.

If you ran into issues with `make`, you can try `make clean` and then try again with `make`.

### Execution
The executable file, generated once you have run `make`, is located at `bin/bombescape`. Note that config files and logs will be placed at where you called the executable file, not necessarily where the executable file is located.

<!-- README REQUIREMENT

▪ Identification of the team members.
▪ A description of your game and introduce the game rules.
▪ A list of features that you have implemented and explain how each coding element 1 to 5 listed under the coding requirements aforementioned support your features.
▪ A list of non-standard C/C++ libraries, if any, that are used in your work and integrated to your code repo. Please also indicate what features in your game are supported by these libraries.
▪ Compilation and execution instructions. This serves like a "Quick start" of your game. The teaching team will follow your instructions to compile and run your game.
-->
