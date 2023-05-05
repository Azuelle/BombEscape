// interface.cpp

#include "interface.h"

#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <algorithm>
#include <string>

#include "gamestate.h"
#include "player.h"
#include "render.h"

// Display in-game HUD, map, player & entities
void display(GameState &state, Win w) {
    // initscr();
    // noecho();
    // curs_set(0);
    // start_color();

    WINDOW *win = w.win;
    int yMax = w.yMax;
    int xMax = w.xMax;
    box(win, 0, 0);

    std::string status_bar[3] = {"HP", "Score", "Time Survived (s)"};
    int corY = w.getSizeY() - 2;

    wattron(win, A_UNDERLINE);
    mvwprintw(win, corY - 1, 1, std::string(w.getSizeX() - 1, ' ').c_str());
    wattroff(win, A_UNDERLINE);

    // get status from gamestate and player
    int duration = duration_cast<seconds>(state.getCurrentDuration()).count();
    long long score = state.getScore();
    int hp = state.player->getHP();

    // int hp = 88;
    // long long score = 45;
    // int duration = 98;

    int pos = 1, score_len = std::max(7, int(std::to_string(score).size()));

    // Tags
    wattron(win, A_BOLD);
    init_pair(0, COLOR_CYAN, COLOR_BLACK);

    // STATUS
    wattron(win, COLOR_PAIR(0));
    mvwprintw(win, corY, pos, "STATUS");
    wattroff(win, COLOR_PAIR(0));

    // HP
    pos += 6 + 3;
    wattron(win, A_STANDOUT);
    mvwprintw(win, corY, pos, status_bar[0].c_str());

    // Score
    pos += status_bar[0].size() + 1 + std::to_string(hp).size() + 1 +
           std::to_string(state.player->getMaxHP()).size() + 3;
    mvwprintw(win, corY, pos, status_bar[1].c_str());

    // Time Survived (s)
    pos += status_bar[1].size() + 1 + score_len + 3;
    mvwprintw(win, corY, pos, status_bar[2].c_str());

    wattroff(win, A_STANDOUT);
    wattroff(win, A_BOLD);

    // Stats
    // HP 3/3
    pos = 1 + 6 + 3 + status_bar[0].size() + 1;
    mvwprintw(
        win, corY, pos,
        (std::to_string(hp) + "/" + std::to_string(state.player->getMaxHP()))
            .c_str());

    // Score 1000000
    pos += std::to_string(hp).size() + 1 +
           std::to_string(state.player->getMaxHP()).size() + 3 +
           status_bar[1].size() + 1;
    mvwprintw(win, corY, pos, std::to_string(score).c_str());

    // Time Survived (s) 10000
    pos += score_len + 3 + status_bar[2].size() + 1;
    mvwprintw(win, corY, pos, std::to_string(duration).c_str());

    // Print map on screen
    // Get rendered map
    std::vector<std::string> map_string = renderMap(state);
    // Get offset to center the map
    int yOffset = w.getYCenterOffset() - 1 - map_string.size() / 2;
    int xOffset = w.getXCenterOffset() - map_string[0].size() / 2;
    // Print
    for (int i = 0; i < map_string.size(); i++)
        mvwprintw(win, yOffset + i, xOffset, map_string[i].c_str());

    wrefresh(win);
}
