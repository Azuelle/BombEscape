// player.h

#ifndef PLAYER_H_
#define PLAYER_H_

#include <chrono>
using namespace std::chrono;

class Player;

#include "entity.h"

class Player {
   private:
    int hp = 3;
    int max_hp = 3;
    int bomb_power = 2;
    Pos position;
    static constexpr char pIcon = '@';

    time_point<system_clock> last_moved = system_clock::now();
    duration<double> movement_cd =
        milliseconds(100);  // Interval between movements
    bool bomb_placed = false;

   public:
    char getpIcon() { return pIcon; }

    bool isAlive() { return hp >= 0; }
    void getDamage() {
        if (isAlive()) hp--;
    }
    // Check if player is still in movement cd
    bool moveable() { return system_clock::now() - last_moved > movement_cd; }
    bool canPlaceBomb() { return !bomb_placed; }
    void setBombPlaced(bool stat) { bomb_placed = stat; }

    int getBombPower() { return bomb_power; }
    int getHP() { return hp; }

    template <class T>
    void usePowerUp(T powerup);

    Pos getPosition() { return this->position; }
    // Absolute movement
    void setPosition(Pos position, bool update_last_moved = true) {
        this->position = position;
        if (update_last_moved) last_moved = system_clock::now();
    }
    // Relative movement
    void move(Pos offset, bool update_last_moved = true) {
        this->position += offset;
        if (update_last_moved) last_moved = system_clock::now();
    }
};

#endif
