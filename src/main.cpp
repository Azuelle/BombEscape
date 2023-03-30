// main.cpp

#include <curses.h>
#include <unistd.h>

#include <chrono>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include "display.h"
#include "game_logic.h"
#include "gamestate.h"
#include "io_utils.h"
#include "time_utils.h"

int main() {
    Input usr_input = Input::none;
    GameState gamestate;

    // Initialize curses
    initscr();
    keypad(stdscr, true);

    while (checkRunning()) {
        display();
        usr_input = getInput();
        logic(gamestate, usr_input);

        usleep(FRAME_TIME.count());  // Wait until next frame
    }

    // Cleanup for curses
    endwin();

    return 0;
}
