// menu.h

#ifndef MENU_H
#define MENU_H

#include <curses.h>
#include <stdio.h>
#include <stdlib.h>

#include <algorithm>
#include <string>

#include "init_window.h"
#include "io_utils.h"

inline void switchOptionDisplayState(Win w, int from, int to, int cX[4],
                                     int cY[4], std::string op[4]);
int getOptions(Win w, int cX[4], int cY[4], std::string op[4]);
int runMenu(Win win);

#endif
