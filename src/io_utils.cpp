// io_utils.cpp

#include "io_utils.h"

#include <curses.h>

#include <iostream>
#include <sstream>
#include <string>

Input getInput(Win w) {
    Input usr_input = Input::none;
    // Set up for non-blocking input
    noecho();
    cbreak();
    nodelay(w.win, TRUE);

    int i = wgetch(w.win);
    if (i != ERR) {
        switch (i) {
            case KEY_BACKSPACE: /* user pressed backspace */
                return Input::backspace;
                break;
            case KEY_UP: /* user pressed up arrow key */
                return Input::up;
                break;
            case KEY_DOWN: /* user pressed down arrow key */
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
            case 10: /* Enter */
                return Input::enter;
                break;
        }
    }
    return usr_input;
}

// get strings from the users
// if the input exceeds the limits, ask users to input again.
// return a string, input a max length.

std::string getString(const unsigned int max_len) {
    std::string str = "";
    echo();
    nocbreak();
    while (str.size() <= max_len) {
        str += getch();
        if (str.size() > max_len) {
            addstr("Your input exceeds the limit. Please input again.");
        }
    }
    noecho();
    cbreak();
    nodelay(stdscr, true);
    return str;
}

std::string getString(
    int x, int y,
    const unsigned int max_len) {  
    std::string str = "";
    move(x, y);
    echo();
    nocbreak();
    while (str.size() <= max_len) {
        str += getch();
        if (str.size() > max_len) {
            addstr("Your input exceeds the limit. Please input again.");
        }
    }
    noecho();
    cbreak();
    nodelay(stdscr, true);
    return str;
}

template <>
int print(std::string content, const unsigned int max_len) {
    return addnstr(content.c_str(), max_len);
}
template <>
int print(char content[], const unsigned int max_len) {
    return addnstr(content, max_len);
}
template <>
int print(char content, const unsigned int max_len) {
    char str[2] = {content};
    return addnstr(str, max_len);
}
template <>
int print(bool content, const unsigned int max_len) {
    return addnstr(content ? "true" : "false", max_len);
}

template <>
int mvprint(std::string content, int x, int y, const unsigned int max_len) {
    return mvaddnstr(y, x, content.c_str(), max_len);
}
template <>
int mvprint(char content[], int x, int y, const unsigned int max_len) {
    return mvaddnstr(y, x, content, max_len);
}
template <>
int mvprint(char content, int x, int y, const unsigned int max_len) {
    char str[2] = {content};
    return mvaddnstr(y, x, str, max_len);
}
template <>
int mvprint(bool content, int x, int y, const unsigned int max_len) {
    return mvaddnstr(y, x, content ? "true" : "false", max_len);
}
