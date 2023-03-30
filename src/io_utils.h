// io_utils.h

#ifndef CONTROL_H
#define CONTROL_H

enum class Input {
    // Directions
    up,     // Up
    down,   // Down
    left,   // Left
    right,  // Right

    place,  // Place bomb

    none  // No input
};

/**
 * Acquires input from user.
 * Returns the input from user as type Input.
 */
Input getInput();

/**
 * Expansion on curses.h's addstr() / addnstr().
 * max_len determines the maximum string length to print. If max_len = -1, then
 * there won't be any limiting and the entire content will be printed.
 * Returns the return value from addnstr().
 */
int print(std::string content, int max_len = -1);
template <typename T>
int print(T content, int max_len = -1);

/**
 * Expansion on curses.h's mvaddstr() / mvaddnstr().
 * max_len determines the maximum string length to print. If max_len =-1, then
 * there won't be any limiting and the entire content will be printed.
 * x, y are screen coordinates (see curses.h documentation for detail).
 * Returns the return value from addnstr().
 */
int mvprint(std::string content, int x, int y, int max_len = -1);
template <typename T>
int mvprint(T content, int x, int y, int max_len = -1);

#endif
