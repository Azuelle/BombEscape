// entity.cpp

#include "entity.h"

#include <vector>

void Bomb::onDeath(Player* player, std::vector<Entity*>& entity_list) {
    this->alreadyDied = true;
    if (this->inRange(player->getPosition())) player->getDamage();

    // Restores player ability if this is placed by player
    if (this->isPlacedByPlayer()) player->setBombPlaced(false);

    for (auto itr = entity_list.begin(); itr != entity_list.end(); itr++)
        if (this->inRange((*itr)->getPosition()) && !(*itr)->checkAlreadyDied())
            (*itr)->onDeath(player, entity_list);
};

bool Bomb::inRange(Pos p) { return this->position.distance(p) <= bomb_power; }
