// player.h

#ifndef PLAYER_H_
#define PLAYER_H_

class Player;

#include "entity.h"

// Describes player health state
enum class HealthState {
    alive,  // Normal state
    dying,  // Low HP
    dead    // HP <= 0
};

// Describes shield state
enum class ShieldState { none, broken, normal };

class Player {
   private:
    HealthState health;
    ShieldState shield;
    int health_val;
    int speed;
    int bomb_count;     // Number of bombs in hand
    int bomb_capacity;  // Maximum number of bombs a player can hold
    Pos position;
    double shield_time;
    double speed_time;
    double frozen_time;

   public:
    Player();
    ~Player();

    bool isAlive() { return health == HealthState::alive; }
    bool isDying() { return health == HealthState::dying; }
    bool isDead() { return health == HealthState::dead; }
    bool hasShield() { return shield != ShieldState::none; }
    int getBombCount() { return bomb_count; }
    int getBombCapacity() { return bomb_capacity; }
    int getHealth() { return health_val; }

    Pos getPosition() { return this->position; }
    // Absolute movement
    void setPosition(Pos position) { this->position = position; }
    // Relative movement
    void move(Pos offset) { this->position += offset; }

    double getShieldTime() { return shield_time; }
    double getSpeedTime() { return speed_time; }
    double getFrozenTime() { return frozen_time; }

    HealthState getHealthState() { return health; }
    ShieldState getShield() { return shield; }
};

#endif
