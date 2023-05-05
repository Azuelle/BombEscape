#include <curses.h>

#include <iostream>

#include "../src/init_window.h"
#include "../src/menu.h"

int main() {
    Win w = initWindow();
    if (w.validSize()) runMenu(w);
    endwin();
    std::cout << w.xMax << ", " << w.yMax << std::endl;
    if (!w.validSize())
        std::cerr << "Terminal or window too small!" << std::endl
                  << "Minimal requirement: Width " << w.xRequirement
                  << ", Height " << w.yRequirement << std::endl;
}
