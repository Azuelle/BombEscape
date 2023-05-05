#include <iostream>

#include "../src/gamestate.h"
#include "../src/map_gen.h"
#include "../src/render.h"

using namespace std;

int main() {
    Playfield map(30, 14);
    Player pl;
    pl.setPosition({1, 1});
    GameState gs(&pl, &map);
    vector<string> m = renderMap(gs);
    for (auto i : m) cout << i << endl;

    return 0;
}
