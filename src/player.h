// player.h

#ifndef PLAYER_H_
#define PLAYER_H_

// Describes player actions
enum PState
{
    PState_walk,
    PState_walk_hold,
    PState_death,
    PState_place, //Placing a bomb
    PState_frozen //Frozen
};

// Describes player health state
enum PHealth
{
    PHealth_alive, //Normal state
    PHealth_dying, //Low HP
    PHealth_dead //HP <= 0
};

// Describes shield state
enum PShield
{
    PShield_none,
    PShield_normal,
    PShield_vanishing
};

class Player
{
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
    inline bool IsAlive();
    inline bool IsDying();
    inline bool IsDead();
    inline bool HasShield();
    inline int PositionX();
    inline int PositionY();
    inline int GetBombs();
    inline int GetBombMax();
    inline int GetBombMaxToPlace();
    inline int GetHealth();
    inline double GetShieldTime();
    inline double GetSpeedTime();
    inline double GetFrozenTime();

    inline PState GetState();
    inline PHealth GetHealthState();
    inline PShield GetShield();
};

inline bool Player::IsAlive() { return p_health == PHealth_alive; }
inline bool Player::IsDying() { return p_health == PHealth_dying; }
inline bool Player::IsDead() { return p_health == PHealth_dead; }
inline bool Player::HasShield() { return p_shield == PShield_normal || p_shield == PShield_vanishing; }
inline int Player::GetBombs() { return p_bomb_num; }
inline int Player::GetBombMax() { return p_bomb_max; }
inline int Player::GetBombMaxToPlace() { return p_bomb_max_to_place; }
inline int Player::GetHealth() { return p_health_val; };
inline int Player::PositionX() { return p_x; }
inline int Player::PositionY() { return p_y; }
inline PHealth Player::GetHealthState() { return p_health; }
inline PShield Player::GetShield() { return p_shield; }
inline PState Player::GetState() { return p_state; }
inline double Player::GetShieldTime() { return p_shield_time; }
inline double Player::GetSpeedTime() { return p_speed_time; }
inline double Player::GetFrozenTime(){ return p_frozen_time; }


#endif
