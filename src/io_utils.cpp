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
                return Input::backspace;
                break;
            case KEY_UP: /* user pressed up arrow key */
                return Input::up;
                break;
            case KEY_DOWN: /* user pressed up arrow key */
                return Input::down;
                break;
            case KEY_LEFT:
                return Input::left;
                break;
            case KEY_RIGHT:
                return Input::right;
                break;
            case 32: /* user pressed space key */
                return Input::place;
                break;    
            case KEY_IC:  // Insert char or enter insert mode
                return Input::chars;
                break;
            case KEY_ENTER:  // Enter or send
                return Input::enter;
                break;
            /*case KEY_EXIT:  // exit the game
                break; */
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
