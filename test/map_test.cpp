#include <iostream>

#include "../src/gamestate.h"
#include "../src/map_gen.h"
#include "../src/render.h"

using namespace std;

int main() {
    Playfield map(14, 14, generateMap(14, 14));
    Player pl;
    GameState gs(pl, map);
    for (auto i : renderMap(gs)) cout << i << endl;

    return 0;
}
