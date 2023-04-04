// player.h

#ifndef PLAYER_H_
#define PLAYER_H_

// Describes player actions
enum PState {
  PState_walk,
  PState_walk_hold,
  PState_death,
  PState_place, //Placing a bomb
  PState_frozen //Frozen
};

// Describes player health state
enum PHealth {
  PHealth_alive, //Normal state
  PHealth_dying, //Low HP
  PHealth_dead //HP <= 0
};

// Describes shield state
enum PShield {
  PShield_none,
  PShield_normal,
  PShield_vanishing
};

class Player {
  private:
    PState p_state;
    PHealth p_health;
    PShield p_shield;
    int p_health_val;
    int p_speed;
    int p_bomb_num;//Number of bombs held
    int p_bomb_max;//Maximum number of bombs a player can hold
    int p_bomb_max_to_place;//Maximum number of bombs a player can place at the same time
    int p_x;
    int p_y;
    double p_shield_time;
    double p_speed_time;
    double p_frozen_time;
  public:
    Player();
    ~Player();
    inline bool isAlive();
    inline bool isDying();
    inline bool isDead();
    inline bool hasShield();
    inline int positionX();
    inline int positionY();
    inline int getBombs();
    inline int getBombMax();
    inline int getBombMaxToPlace();
    inline int getHealth();
    inline double getShieldTime();
    inline double getSpeedTime();
    inline double getFrozenTime();

    inline PState getState();
    inline PHealth getHealthState();
    inline PShield getShield();
};

inline bool Player::isAlive() { return p_health == PHealth_alive; }
inline bool Player::isDying() { return p_health == PHealth_dying; }
inline bool Player::isDead() { return p_health == PHealth_dead; }
inline bool Player::hasShield() { return p_shield == PShield_normal || p_shield == PShield_vanishing; }
inline int Player::getBombs() { return p_bomb_num; }
inline int Player::getBombMax() { return p_bomb_max; }
inline int Player::getBombMaxToPlace() { return p_bomb_max_to_place; }
inline int Player::getHealth() { return p_health_val; };
inline int Player::positionX() { return p_x; }
inline int Player::positionY() { return p_y; }
inline PHealth Player::getHealthState() { return p_health; }
inline PShield Player::getShield() { return p_shield; }
inline PState Player::getState() { return p_state; }
inline double Player::getShieldTime() { return p_shield_time; }
inline double Player::getSpeedTime() { return p_speed_time; }
inline double Player::getFrozenTime(){ return p_frozen_time; }


#endif
