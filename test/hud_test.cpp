#include <unistd.h>

#include "../src/gamestate.h"
#include "../src/init_window.h"
#include "../src/interface.h"
#include "../src/time_utils.h"

int main() {
    Playfield map(30, 14);
    Player pl;
    pl.setPosition({1, 1});
    map.entity_list.push_back(new Bomb(Pos{6, 6}, 3));
    map.entity_list.push_back(new Barricade(Pos{6, 7}));
    map.entity_list.push_back(new Healing(Pos{6, 8}));
    map.entity_list.push_back(new BombPower(Pos{6, 9}));
    GameState gs(&pl, &map);
    while (gs.getCurrentDuration() < std::chrono::seconds(15)) {
        display(gs, initWindow());
        usleep(FRAME_TIME.count());
    }
    endwin();
    return 0;
}
