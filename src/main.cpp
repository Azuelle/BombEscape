// main.cpp

#include <curses.h>
#include <unistd.h>

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include "control.h"
#include "display.h"
#include "game_logic.h"

const int FRAME_CAP = 30;

int main() {
    int frame_time_us =
        1000000 / FRAME_CAP;  // Length of a frame, in microseconds
    input usr_input = input::none;

    system("clear");  // Clear the screen before running
    while (checkRunning()) {
        display();
        usr_input = getInput();
        logic(usr_input);

        usleep(frame_time_us);  // Wait until next frame
    }
    system("clear");  // Clear the screen after running
    return 0;
}
