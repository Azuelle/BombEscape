// ranking.cpp

#include "ranking.h"

// Displays the ranking of the player
void showRanking(Win w) {
    WINDOW* win = w.win;
    auto ranks = getRank();
    const int listing_offset_x = w.getXCenterOffset() - 11;

    const int title_y = w.getYCenterOffset() -
                        (4 + (ranks.size() ? ranks.size() * 2 - 1 : 2) + 3) / 2;

    int current_listing_offset_y = title_y + 3;

    werase(w.win);
    curs_set(0);

    box(win, 0, 0);

    wattron(win, A_BOLD);
    wattron(win, A_UNDERLINE);
    wattron(win, A_STANDOUT);
    mvwprintw(win, title_y, w.getXCenterOffset() - 5, "Scoreboard");
    wattroff(win, A_BOLD);
    wattroff(win, A_UNDERLINE);
    wattroff(win, A_STANDOUT);

    if (!ranks.size()) {
        mvwprintw(win, current_listing_offset_y, w.getXCenterOffset() - 6,
                  "No Entry Yet");
        mvwprintw(win, ++current_listing_offset_y, w.getXCenterOffset() - 10,
                  "Waiting for yours! ;)");
        current_listing_offset_y += 2;
    } else
        for (auto const& [key, val] : ranks) {
            std::string output =
                std::string(std::max(12, int(key.size()) + 2), ' ') +
                std::to_string(val);
            mvwprintw(win, current_listing_offset_y, listing_offset_x,
                      output.c_str());

            wattron(win, A_STANDOUT);
            mvwprintw(win, current_listing_offset_y, listing_offset_x,
                      key.c_str());
            wattroff(win, A_STANDOUT);

            current_listing_offset_y += 2;
        }
    wattron(win, A_ITALIC);
    mvwprintw(win, ++current_listing_offset_y, w.getXCenterOffset() - 17,
              "~ Press the Confirm key to leave ~");
    wattroff(win, A_ITALIC);

    wrefresh(win);
}
