// init_window.h

#ifndef INIT_WINDOW_H
#define INIT_WINDOW_H

#include <curses.h>
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <iostream>

struct Win {
    WINDOW* win;

    int yMax;
    int xMax;

    int border_ratio_y;
    int border_ratio_x;

    static constexpr int yRequirement = 24;
    static constexpr int xRequirement = 96;
    static constexpr int ySuggestion = 30;
    static constexpr int xSuggestion = 108;

    int getYCenterOffset() {
        return yMax / 2 - yMax / (this->border_ratio_y * 2);
    }
    int getXCenterOffset() {
        return xMax / 2 - xMax / (this->border_ratio_x * 2);
    }
    bool validSize() { return yMax >= yRequirement && xMax >= xRequirement; }
    void printWindowHint() {
        std::cerr << "Terminal or window too small!" << std::endl
                  << "Minimal size requirement: Width " << this->xRequirement
                  << ", Height " << this->yRequirement << std::endl
                  << "Suggested size: Width " << this->xSuggestion
                  << ", Height " << this->ySuggestion << std::endl;
    }
};

Win initWindow(int border_ratio_y = 5, int border_ratio_x = 6);

#endif
