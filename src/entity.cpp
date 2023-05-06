// entity.cpp

#include "entity.h"

#include <vector>

void Bomb::onDeath(Player* player, std::vector<Entity*>& entity_list) {
    this->alreadyDied = true;
    player->addAdditionalScore(this->bomb_power * 250);
    Pos p_pos = player->getPosition();
    if ((p_pos.x == this->position.x || p_pos.y == this->position.y) &&
        this->inRange(p_pos))
        player->getDamage();

    // Restores player ability if this is placed by player
    if (this->isPlacedByPlayer()) player->setBombPlaced(false);

    for (auto itr = entity_list.begin(); itr != entity_list.end(); itr++)
        if (this->inRange((*itr)->getPosition()) && !(*itr)->checkAlreadyDied())
            (*itr)->onDeath(player, entity_list);
};

bool Bomb::inRange(Pos p) { return this->position.distance(p) <= bomb_power; }
