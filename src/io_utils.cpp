// io_utils.cpp

#include "io_utils.h"

#include <curses.h>

// Acquire input from user
// Takes 0 arguments
// Returns the input from user as enum class input
Input getInput() {
    Input usr_input = Input::none;

    // Set up for non-blocking input
    noecho();
    cbreak();
    nodelay(stdscr, TRUE);

    int i = getch();
    if (i != ERR) {
        switch (i) {
            // Determine user input here
            // TODO: Allow the user to customize the buttons for controls
        }
    }
    return usr_input;
}
