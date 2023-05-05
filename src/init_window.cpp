// init_window.cpp

#include "init_window.h"

Win initWindow(int border_ratio_y, int border_ratio_x) {
    initscr();
    noecho();
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    // Initialize the size of the menu
    return Win{
        newwin(yMax - yMax / border_ratio_y, xMax - xMax / border_ratio_x,
               yMax / (border_ratio_y * 2), xMax / (border_ratio_x * 2)),
        yMax, xMax, border_ratio_y, border_ratio_x};
}
