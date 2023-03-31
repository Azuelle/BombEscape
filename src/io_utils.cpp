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
          case KEY_BACKSPACE: /* user pressed backspace */
            break; 
          case KEY_UP:  /* user pressed up arrow key */
            break;
          case KEY_DOWN:  /* user pressed up arrow key */
            break;
          case KEY_LEFT:
            break;
          case KEY_RIGHT:
            break;
          case KEY_DC:        // Delete character
            break;
          case KEY_IC:        // Insert char or enter insert mode
            break;
          case KEY_ENTER :       // Enter or send
            break;
          case KEY_SUSPEND:  // To suspend the game
            break;
          case KEY_EXIT: // exit the game
            break;
          // case KEY_F(n):        // Function keys, for 0 <= n >= 63

        }
    }
    return usr_input;
}

template <typename T>
int print(T content, int max_len = -1) {
    return addnstr(std::to_string(content).c_str(), max_len);
}
template <>
int print(std::string content, int max_len) {
    return addnstr(content.c_str(), max_len);
}
template <>
int print(char content, int max_len) {
    char str[2] = {content};
    return addnstr(str, max_len);
}
template <>
int print(bool content, int max_len) {
    return addnstr(content ? "true" : "false", max_len);
}

template <typename T>
int mvprint(T content, int x, int y, int max_len = -1) {
    return mvaddnstr(y, x, std::to_string(content).c_str(), max_len);
}
template <>
int mvprint(std::string content, int x, int y, int max_len) {
    return mvaddnstr(y, x, content.c_str(), max_len);
}
template <>
int mvprint(char content, int x, int y, int max_len) {
    char str[2] = {content};
    return mvaddnstr(y, x, str, max_len);
}
template <>
int mvprint(bool content, int x, int y, int max_len) {
    return mvaddnstr(y, x, content ? "true" : "false", max_len);
}
