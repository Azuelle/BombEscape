// main.cpp

#include <curses.h>
#include <unistd.h>

#include <chrono>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include "game_logic.h"
#include "gamestate.h"
#include "interface.h"
#include "io_utils.h"
#include "time_utils.h"

int main() {
    GameState gamestate;

    // Initialize curses
    initscr();
    keypad(stdscr, true);

    while (checkRunning()) {
        display();
        logic(gamestate);
    }

    // Cleanup for curses
    endwin();

    return 0;
}
