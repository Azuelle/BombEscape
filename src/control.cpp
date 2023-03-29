// control.cpp

#include "control.h"

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
          case KEY_BACKSPACE: /* user pressed backspace */ 
          case KEY_UP:  /* user pressed up arrow key */
          case KEY_DOWN:  /* user pressed up arrow key */
          case KEY_LEFT:
          case KEY_RIGHT:
          case KEY_HOME:        // Home key
          case KEY_DC:        // Delete character
          case KEY_IC:        // Insert char or enter insert mode
          case KEY_ENTER :       // Enter or send
          // case KEY_F(n):        // Function keys, for 0 <= n >= 63

        }
    }
    return usr_input;
}
