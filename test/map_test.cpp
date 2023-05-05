#include <iostream>

#include "../src/gamestate.h"
#include "../src/map_gen.h"
#include "../src/render.h"

using namespace std;

int main() {
    Playfield map(30, 14);
    Player pl;
    pl.setPosition({1, 1});
    map.entity_list.push_back(new Bomb(Pos{6, 6}, 3));
    map.entity_list.push_back(new Barricade(Pos{6, 7}));
    map.entity_list.push_back(new Healing(Pos{6, 8}));
    map.entity_list.push_back(new BombPower(Pos{6, 9}));
    GameState gs(&pl, &map);
    vector<string> m = renderMap(gs);
    for (auto i : m) cout << i << endl;

    return 0;
}
