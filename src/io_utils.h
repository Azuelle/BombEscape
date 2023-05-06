// io_utils.h

#ifndef IO_UTILS_H
#define IO_UTILS_H

#include <curses.h>

#include <iostream>
#include <map>
#include <sstream>
#include <string>

#include "config.h"
#include "init_window.h"

enum class Input : int {
    // Directions
    up,         // Up
    down,       // Down
    left,       // Left
    right,      // Right
    place,      // Place bomb, defaults to space
    confirm,    // Defaults to enter
    backspace,  // Backspace
    none        // No input
};

/**
 * Acquires input from user.
 * Returns the input from user as type Input.
 */
Input getInput(Win w);

// get strings from the users
// if the input exceeds the limits, ask users to input again.
// return a string, input a max length.
std::string getString(Win w, const unsigned int max_len);
std::string getString(Win w, int x, int y, const unsigned int max_len);

/**
 * Expansion on curses.h's addstr() / addnstr().
 * max_len determines the maximum string length to print. If max_len = -1, then
 * there won't be any limiting and the entire content will be printed.
 * Returns the return value from addnstr().
 */
template <typename T>
int print(T content, const unsigned int max_len = -1) {
    return addnstr(std::to_string(content).c_str(), max_len);
}
template <>
int print(std::string content, const unsigned int max_len);
template <>
int print(char content[], const unsigned int max_len);
template <>
int print(char content, const unsigned int max_len);
template <>
int print(bool content, const unsigned int max_len);

/**
 * Expansion on curses.h's mvaddstr() / mvaddnstr().
 * max_len determines the maximum string length to print. If max_len =-1, then
 * there won't be any limiting and the entire content will be printed.
 * x, y are screen coordinates (see curses.h documentation for detail).
 * Returns the return value from addnstr().
 */
template <typename T>
int mvprint(T content, int x, int y, const unsigned int max_len = -1) {
    return mvaddnstr(y, x, std::to_string(content).c_str(), max_len);
}
template <>
int mvprint(std::string content, int x, int y, const unsigned int max_len);
template <>
int mvprint(char content[], int x, int y, const unsigned int max_len);
template <>
int mvprint(char content, int x, int y, const unsigned int max_len);
template <>
int mvprint(bool content, int x, int y, const unsigned int max_len);

#endif
