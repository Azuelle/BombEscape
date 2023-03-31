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
