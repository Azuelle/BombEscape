// interface.cpp

#include "interface.h"

#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <string>

#include "gamestate.h"
#include "player.h"

// Display in-game HUD, map, player & entities
void display(GameState &state, WINDOW *win) {
    // initscr();
    // noecho();
    // curs_set(0);
    // start_color();

    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    box(win, 0, 0);

    std::string status_bar[4] = {"[STATUS]",
                                 "HP: ", "Score: ", "Survival Time: "};
    wrefresh(win);
    int corY = (yMax - yMax / 5) / 2 + (yMax - yMax / 5) / 2.12;

    wattron(win, A_BOLD);

    for (int i = 1; i < xMax / 2 - 1; i++) {
        mvwprintw(win, corY - 1, i, "-");
    }
    // status bar: 11
    mvwprintw(win, corY, 1, status_bar[0].c_str());
    // HP: 3
    mvwprintw(win, corY, 12, status_bar[1].c_str());
    // Score: 6
    mvwprintw(win, corY, 19, status_bar[2].c_str());
    // Survival Time: 15
    mvwprintw(win, corY, 29, status_bar[3].c_str());

    // get status from gamestate and player
    int duration = duration_cast<seconds>(state.getCurrentDuration()).count();
    long long score = state.getScore();
    int hp = state.player->getHP();

    // int hp = 88;
    // long long score = 45;
    // int duration = 98;

    mvwprintw(win, corY, 15, "%d", hp);
    mvwprintw(win, corY, 25, "%lld", score);
    mvwprintw(win, corY, 43, "%d", duration);

    wattroff(win, A_BOLD);
    wrefresh(win);
}
