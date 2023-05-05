#include <curses.h>

#include "../src/init_window.h"
#include "../src/menu.h"

int main() {
    runMenu(initWindow());
    endwin();
}
