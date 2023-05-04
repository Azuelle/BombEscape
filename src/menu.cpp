#include <curses.h>
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

#include <string>

using namespace std;

bool isStart(int pos) {
    if (pos == 0) {
        return true;
    } else {
        return false;
    }
}

void chooseGame(WINDOW *win, int cX[4], int cY[4], string op[4], int choice,
                int pos) {}

void RUN(WINDOW *win, int cX[4], int cY[4], string op[4], int choice, int pos) {
    bool isRun = true;
    while (isRun) {
        choice = wgetch(win);
        switch (choice) {
            case KEY_UP:
                switch (pos) {
                    case 0:
                        wattron(win, A_BOLD);
                        mvwprintw(win, cY[pos], cX[pos], op[pos].c_str());
                        wattroff(win, A_BOLD);
                        pos = 3;
                        wattron(win, A_STANDOUT);
                        mvwprintw(win, cY[pos], cX[pos], op[pos].c_str());
                        wattroff(win, A_STANDOUT);
                        break;
                    case 1:
                        wattron(win, A_BOLD);
                        mvwprintw(win, cY[pos], cX[pos], op[pos].c_str());
                        wattroff(win, A_BOLD);
                        pos = 0;
                        wattron(win, A_STANDOUT);
                        mvwprintw(win, cY[pos], cX[pos], op[pos].c_str());
                        wattroff(win, A_STANDOUT);
                        break;
                    case 2:
                        wattron(win, A_BOLD);
                        mvwprintw(win, cY[pos], cX[pos], op[pos].c_str());
                        wattroff(win, A_BOLD);
                        pos = 1;
                        wattron(win, A_STANDOUT);
                        mvwprintw(win, cY[pos], cX[pos], op[pos].c_str());
                        wattroff(win, A_STANDOUT);
                        break;
                    case 3:
                        wattron(win, A_BOLD);
                        mvwprintw(win, cY[pos], cX[pos], op[pos].c_str());
                        wattroff(win, A_BOLD);
                        pos = 2;
                        wattron(win, A_STANDOUT);
                        mvwprintw(win, cY[pos], cX[pos], op[pos].c_str());
                        wattroff(win, A_STANDOUT);
                        break;
                }
                break;
            case KEY_DOWN:
                switch (pos) {
                    case 0:
                        wattron(win, A_BOLD);
                        mvwprintw(win, cY[pos], cX[pos], op[pos].c_str());
                        wattroff(win, A_BOLD);
                        pos = 1;
                        wattron(win, A_STANDOUT);
                        mvwprintw(win, cY[pos], cX[pos], op[pos].c_str());
                        wattroff(win, A_STANDOUT);
                        break;
                    case 1:
                        wattron(win, A_BOLD);
                        mvwprintw(win, cY[pos], cX[pos], op[pos].c_str());
                        wattroff(win, A_BOLD);
                        pos = 2;
                        wattron(win, A_STANDOUT);
                        mvwprintw(win, cY[pos], cX[pos], op[pos].c_str());
                        wattroff(win, A_STANDOUT);
                        break;
                    case 2:
                        wattron(win, A_BOLD);
                        mvwprintw(win, cY[pos], cX[pos], op[pos].c_str());
                        wattroff(win, A_BOLD);
                        pos = 3;
                        wattron(win, A_STANDOUT);
                        mvwprintw(win, cY[pos], cX[pos], op[pos].c_str());
                        wattroff(win, A_STANDOUT);
                        break;
                    case 3:
                        wattron(win, A_BOLD);
                        mvwprintw(win, cY[pos], cX[pos], op[pos].c_str());
                        wattroff(win, A_BOLD);
                        pos = 0;
                        wattron(win, A_STANDOUT);
                        mvwprintw(win, cY[pos], cX[pos], op[pos].c_str());
                        wattroff(win, A_STANDOUT);
                        break;
                }
                break;
            default:
                if (choice == 10) {
                    erase();
                    refresh();
                    isRun = false;
                }
        }
    }
}

int main(int argc, char **argv) {
    // Initialize the game menu
    initscr();
    noecho();
    curs_set(0);
    start_color();

    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    // Initialize the size of the menu
    WINDOW *win = newwin(yMax - yMax / 5, xMax / 2, yMax / 10, xMax / 4);
    box(win, 0, 0);

    // Creating variables for the game option
    string option1 = "Start Game";
    string option2 = "Ranking";
    string option3 = "Settings";
    string option4 = "Quit";

    // Creating variables for the game title

    string title_1 =
        " ____                     _       ______                              "
        " ";
    string title_2 =
        "|  _ \\                   | |     |  ____|                            "
        "  ";
    string title_3 =
        "| |_) |  ___   _ __ ___  | |__   | |__    ___   ___  __ _  _ __    "
        "___ ";
    string title_4 =
        "|  _ <  / _ \\ | '_ ` _ \\ | '_ \\  |  __|  / __| / __|/ _` || '_ \\  "
        "/ _ \\";
    string title_5 =
        "| |_) || (_) || | | | | || |_) | | |____ \\__ \\| (__| (_| || |_) ||  "
        "__/";
    string title_6 =
        "|____/  \\___/ |_| |_| |_||_.__/  |______||___/ \\___|\\__,_|| .__/  "
        "\\___|";
    string title_7 =
        "                                                          | |         "
        " ";
    string title_8 =
        "                                                          |_|";

    // Setting the options to be bold

    // Calculate center coordinates for each option and print them
    int centerY = (yMax - yMax / 5) / 2;
    int centerX1 = (xMax / 4) - (option1.length() / 2);
    int centerX2 = (xMax / 4) - (option2.length() / 2);
    int centerX3 = (xMax / 4) - (option3.length() / 2);
    int centerX4 = (xMax / 4) - (option4.length() / 2);

    // Calculate coordinates for the game title

    int centerTitle = (xMax / 4) - (title_5.length() / 2);

    // Output message for the game option
    // mvwprintw(win, centerY-2, centerX1, option1.c_str());
    wrefresh(win);
    wattron(win, A_STANDOUT);
    mvwprintw(win, centerY - 2, centerX1, option1.c_str());
    wattroff(win, A_STANDOUT);

    wrefresh(win);

    wattron(win, A_BOLD);
    mvwprintw(win, centerY, centerX2, option2.c_str());
    mvwprintw(win, centerY + 2, centerX3, option3.c_str());
    mvwprintw(win, centerY + 4, centerX4, option4.c_str());

    // Output message for the game title

    mvwprintw(win, 5, centerTitle, title_1.c_str());
    mvwprintw(win, 6, centerTitle, title_2.c_str());
    mvwprintw(win, 7, centerTitle, title_3.c_str());
    mvwprintw(win, 8, centerTitle, title_4.c_str());
    mvwprintw(win, 9, centerTitle, title_5.c_str());
    mvwprintw(win, 10, centerTitle, title_6.c_str());
    mvwprintw(win, 11, centerTitle, title_7.c_str());
    mvwprintw(win, 12, centerTitle, title_8.c_str());

    wattroff(win, A_BOLD);

    // To set the initial stage to Start Game

    // To enable the User Input to be arrow key
    keypad(win, true);
    int choice = 0;
    // Create array for x,y coordinate and the option.
    string opArray[4] = {"Start Game", "Ranking", "Settings", "Quit"};
    int centerXArray[4] = {centerX1, centerX2, centerX3, centerX4};
    int centerYArray[4] = {centerY - 2, centerY, centerY + 2, centerY + 4};

    int pos = 0;
    // Highlight
    RUN(win, centerXArray, centerYArray, opArray, choice, pos);

    refresh();

    endwin();
    return 0;
}
