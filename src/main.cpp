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
#include "init_window.h"
#include "interface.h"
#include "io_utils.h"
#include "time_utils.h"

int main() {
    GameState gamestate;

    // Initialize curses window
    Win w = initWindow();

    while (checkRunning()) logic(gamestate, w);

    // Cleanup for curses
    endwin();

    return 0;
}
