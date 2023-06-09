// menu.cpp

#include "menu.h"

// This Function mainly changes the option display state.
// It takes the win, from, to and centerX, centerY, optionlist as input
// parameter
inline void switchOptionDisplayState(Win w, int from, int to, int cX[4],
                                     int cY[4], std::string op[4]) {
    WINDOW *win = w.win;
    wrefresh(win);
    wattron(win, A_BOLD);
    mvwprintw(win, cY[from], cX[from], op[from].c_str());
    wattroff(win, A_BOLD);
    wrefresh(win);
    wrefresh(win);
    wattron(win, A_STANDOUT);
    mvwprintw(win, cY[to], cX[to], op[to].c_str());
    wattroff(win, A_STANDOUT);
    wrefresh(win);
}

// This function use switchOptionDisplayState function to switch the option
// display It takes the win, centerX, centerY, optionlist as input parameter
int getOptions(Win w, int cX[4], int cY[4], std::string op[4]) {
    bool isRun = true;
    int pos = 0;
    while (isRun) {
        Input choice = getInput(w);
        if (choice == Input::up) {
            switchOptionDisplayState(w, pos, (pos + 3) % 4, cX, cY, op);
            pos = (pos + 3) % 4;
        } else if (choice == Input::down) {
            switchOptionDisplayState(w, pos, (pos + 1) % 4, cX, cY, op);
            pos = (pos + 1) % 4;
        } else if (choice == Input::confirm) {
            erase();
            refresh();
            isRun = false;
        }
    }
    return pos;
}

// This function is to initiallize the window, create the ascii art of BOMB
// ESCAPE and display all the game options.
int runMenu(Win w) {
    // Initialize the game menu
    curs_set(0);

    WINDOW *win = w.win;

    werase(win);

    // x, y coords for options
    int optionX[4];
    int optionY[4];

    // Draw outline
    box(w.win, 0, 0);

    // Creating variables for the game option
    std::string option[4] = {"Start Game", "Scoreboard", "Settings", "Quit"};

    // Creating variables for the game title
    std::string title[8] = {
        " ____                     _       ______                              "
        " ",
        "|  _ \\                   | |     |  ____|                            "
        "  ",
        "| |_) |  ___   _ __ ___  | |__   | |__    ___   ___  __ _  _ __    "
        "___ ",
        "|  _ <  / _ \\ | '_ ` _ \\ | '_ \\  |  __|  / __| / __|/ _` || '_ \\  "
        "/ _ \\",
        "| |_) || (_) || | | | | || |_) | | |____ \\__ \\| (__| (_| || |_) ||  "
        "__/",
        "|____/  \\___/ |_| |_| |_||_.__/  |______||___/ \\___|\\__,_|| .__/  "
        "\\___|",
        "                                                          | |         "
        " ",
        "                                                          |_|"};

    // Calculate adaptive distance between title and options
    int gap = std::max(1, (w.yMax - w.yMax / w.border_ratio_y) / 12);

    // Output message for the game option
    // mvwprintw(win, centerY-2, centerX1, option1.c_str());
    wrefresh(win);
    wattron(win, A_STANDOUT);
    mvwprintw(win, optionY[0] = w.getYCenterOffset() - (15 + gap) / 2 + 8 + gap,
              optionX[0] = w.getXCenterOffset() - option[0].length() / 2,
              option[0].c_str());

    wattroff(win, A_STANDOUT);

    wrefresh(win);

    wattron(win, A_BOLD);
    for (int i = 1; i < 4; i++)
        mvwprintw(win,
                  optionY[i] =
                      w.getYCenterOffset() - (15 + gap) / 2 + 8 + gap + 2 * i,
                  optionX[i] = w.getXCenterOffset() - option[i].length() / 2,
                  option[i].c_str());

    // Output message for the game title

    for (int i = 0; i < 8; i++)
        mvwprintw(win, w.getYCenterOffset() - (15 + gap) / 2 + i,
                  w.getXCenterOffset() - title[5].length() / 2,
                  title[i].c_str());

    wattroff(win, A_BOLD);

    // Highlight chosen options
    int pos = getOptions(w, optionX, optionY, option);

    refresh();

    return pos;
}
