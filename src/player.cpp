// player.cpp

#include "player.h"

#include <algorithm>

template <class T>
void Player::usePowerUp(T powerup) {}
template <>
void Player::usePowerUp(Healing h) {
    this->hp = std::min(max_hp, hp + h.getPower());
}
template <>
void Player::usePowerUp(BombPower p) {
    this->bomb_power += p.getPower();
}
