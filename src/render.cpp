// render.cpp

#include "render.h"

#include <iostream>

// return a vector<string> containing the icons of the map

// wall # player @ bomb O barricade ! floor .

std::vector<std::string> renderMap(GameState &state) {
    std::vector<std::string> vec(state.playfield->getHeight(),
                                 std::string(state.playfield->getWidth(), '.'));
    for (int i = 0; i < state.playfield->getHeight(); i++)
        for (int j = 0; j < state.playfield->getWidth(); j++)
            if (state.playfield->isObstacle(j, i)) vec[i].at(j) = '#';

    for (auto itr = state.playfield->entity_list.begin();
         itr != state.playfield->entity_list.end(); itr++) {
        vec[(*itr)->getPosition().y][(*itr)->getPosition().x] =
            (*itr)->getIcon();
    }

    Pos p_pos = state.player->getPosition();
    vec[p_pos.y][p_pos.x] = state.player->getpIcon();

    return vec;
}
