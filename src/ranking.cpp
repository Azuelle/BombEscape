#include <stdio.h>
#include <ncurses.h>
#include <curses.h>
#include <string>
#include <stdlib.h>
#include <unistd.h>
#include <map>
#include <vector>


#include "rank.h"

// This function displays the ranking of the player
void showRanking(){
    initscr();
    noecho();
    curs_set(0);
    //start_color();
    std::map<std::string, int> myrank;
    myrank["Jonathan"] = 100;
    myrank["John"] = 10;
    myrank["Marvolo"] = 105;

    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    WINDOW *win = newwin(yMax-yMax/5, xMax/2, yMax/10, xMax/4);
    box(win, 0, 0);

    std::string rank = "Ranking List";
    int centerX = (xMax/4) - rank.length()/2;
    wrefresh(win);
    wattron(win, A_BOLD);
    mvwprintw(win, 3, centerX, rank.c_str());
    wattroff(win, A_BOLD);
    wrefresh(win);


    //std::map<std::string, int>all_rank = getRank();
    wrefresh(win);
    //vector<pair<string, int> > my_rank = getRank();

    int yRank = 7;

    //for (auto const& [key, val] : myrank) {
        //std::string output = key + ": " + std::to_string(val);
        //mvwprintw(win,yRank,centerX,output.c_str());
        //yRank = yRank+2;
    //}

    std::vector<std::pair<std::string,int>> myVec = {{"name1", 10}, {"name2", 20}, {"name3", 30}};
    for (auto const& [key, val] : myVec) {
        std::string output = key + ": " + std::to_string(val);
        mvwprintw(win,yRank,centerX,output.c_str());
        yRank = yRank +2 ;
    }
    wrefresh(win);

    usleep(2147483647);
    endwin();

}
