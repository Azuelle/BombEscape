// menu.h

#ifndef MENU_H
#define MENU_H

#include <curses.h>
#include <stdio.h>
#include <stdlib.h>

#include <algorithm>
#include <string>

#include "init_window.h"

int getOptions(WINDOW *win, int cX[4], int cY[4], std::string op[4], int choice,
               int pos);
int runMenu(Win win);

#endif
