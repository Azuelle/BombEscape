// io_utils.cpp

#include "io_utils.h"

#include <curses.h>

#include <string>

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

int print(std::string content, int max_len = -1) {
    return addnstr(content.c_str(), max_len);
}
template <typename T>
int print(T content, int max_len = -1) {
    return addnstr(std::to_string(content).c_str(), max_len);
}

int mvprint(std::string content, int x, int y, int max_len = -1) {
    return mvaddnstr(y, x, content.c_str(), max_len);
}
template <typename T>
int mvprint(T content, int x, int y, int max_len = -1) {
    return mvaddnstr(y, x, std::to_string(content).c_str(), max_len);
}
