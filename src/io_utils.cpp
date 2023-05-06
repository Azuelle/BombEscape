// io_utils.cpp

#include "io_utils.h"

static std::map<std::string, int> keymap;

/**
 * Acquires input from user.
 * Returns the input from user as type Input.
 */
Input getInput(Win w) {
    if (!keymap.size()) keymap = getConfig();

    Input usr_input = Input::none;
    // Set up for non-blocking input
    noecho();
    cbreak();
    nodelay(w.win, TRUE);

    int i = wgetch(w.win);

    if (i == keymap["backspace"])
        usr_input = Input::backspace;

    else if (i == keymap["up"])
        usr_input = Input::up;
    else if (i == keymap["down"])
        usr_input = Input::down;
    else if (i == keymap["left"])
        usr_input = Input::left;
    else if (i == keymap["right"])
        usr_input = Input::right;

    else if (i == keymap["place"])
        usr_input = Input::place;
    else if (i == keymap["confirm"])
        usr_input = Input::confirm;

    return usr_input;
}

// get strings from the users
// if the input exceeds the limits, ask users to input again.
// return a string, input a max length.
std::string getString(Win w, const unsigned int max_len) {
    std::string str = "";
    echo();
    nocbreak();
    while (str.size() <= max_len) {
        str += wgetch(w.win);
        if (str.size() > max_len) {
            addstr("Your input exceeds the limit. Please input again.");
        }
    }
    noecho();
    cbreak();
    nodelay(stdscr, true);
    return str;
}

std::string getString(Win w, int x, int y, const unsigned int max_len) {
    std::string str = "";
    move(x, y);
    echo();
    nocbreak();
    while (str.size() <= max_len) {
        str += wgetch(w.win);
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
