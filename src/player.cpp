// player.cpp

#include "player.h"

#include <algorithm>

void Player::usePowerUp(Healing h) {
    this->hp = std::min(max_hp, hp + h.getPower());
}
void Player::usePowerUp(BombPower p) { this->bomb_power += p.getPower(); }
