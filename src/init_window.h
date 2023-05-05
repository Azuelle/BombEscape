// init_window.h

#ifndef INIT_WINDOW_H
#define INIT_WINDOW_H

#include <curses.h>
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct Win {
    WINDOW* win;

    int yMax;
    int xMax;

    int border_ratio_y;
    int border_ratio_x;

    int getYCenterOffset() {
        return yMax / 2 - yMax / (this->border_ratio_y * 2);
    }
    int getXCenterOffset() {
        return xMax / 2 - xMax / (this->border_ratio_x * 2);
    }
};

Win initWindow(int border_ratio_y = 5, int border_ratio_x = 6);

#endif
