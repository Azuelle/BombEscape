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
    Input usr_input = Input::none;
    GameState gamestate;

    // Initialize curses
    initscr();
    keypad(stdscr, true);
    // loop 本体 画面：地图/玩家/血量/分数
    

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
