// player.h

#ifndef PLAYER_H_
#define PLAYER_H_

// Describes player actions
enum class PlayerState {
    walk,
    walk_hold,
    death,
    place,  // Placing a bomb
    frozen  // Frozen
};

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
    PlayerState state;
    HealthState health;
    ShieldState shield;
    int health_val;
    int speed;
    int bomb_count;     // Number of bombs in hand
    int bomb_capacity;  // Maximum number of bombs a player can hold
    int x;
    int y;
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
    int getHealth() { return health_val; };
    int getPositionX() { return x; }
    int getPositionY() { return y; }
    double getShieldTime() { return shield_time; }
    double getSpeedTime() { return speed_time; }
    double getFrozenTime() { return frozen_time; }

    HealthState getHealthState() { return health; }
    ShieldState getShield() { return shield; }
    PlayerState getState() { return state; }
};

#endif
