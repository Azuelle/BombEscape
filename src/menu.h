#ifndef MENU_H
#define MENU_H

#include <curses.h>
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

#include <string>

bool isStart(int pos);
void chooseGame(WINDOW *win, int cX[4], int cY[4], std::string op[4],
                int choice, int pos);
void RUN(WINDOW *win, int cX[4], int cY[4], std::string op[4], int choice,
         int pos);
int main(int argc, char **argv);

#endif
