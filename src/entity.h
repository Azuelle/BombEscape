// entity.h

#ifndef ENTITY_H
#define ENTITY_H

#include <chrono>
#include <cmath>
#include <vector>

using namespace std::chrono;

// For storing position (a pair of x, y coordinates) and easy calculations
struct Pos {
    int x;
    int y;

    // Return the Manhattan distance between two points
    int distance(Pos to) {
        return abs(to.x - this->x) + abs(to.y - this->y);
    }  // What is the use of this function?

    constexpr Pos operator+(const Pos opr) {
        return Pos{this->x + opr.x, this->y + opr.y};
    }
    constexpr Pos operator-(const Pos opr) {
        return Pos{this->x - opr.x, this->y - opr.y};
    }
    Pos& operator+=(const Pos opr) {
        this->x += opr.x, this->y += opr.y;
        return *this;
    }
    Pos& operator-=(const Pos opr) {
        this->x -= opr.x, this->y -= opr.y;
        return *this;
    }
    bool operator==(const Pos opr) {
        return this->x == opr.x && this->y == opr.y;
    }
};

#include "player.h"

// A base class for all kinds of non-player entities on the playfield
class Entity {
   protected:
    Pos position;
    time_point<system_clock> start_time;
    duration<double> lifetime;
    // Indicates whether this Entity's onDeath has already been processed
    bool alreadyDied = false;
    // Indicates whether this Entity dies after a certain amount of time
    bool timed = true;

    static constexpr char icon = ' ';

   public:
    Pos getPosition() { return this->position; }
    // Absolute movement
    void setPosition(Pos position) { this->position = position; }
    // Relative movement
    void move(Pos offset) { this->position += offset; }

    // Checks whether this Entity's timer has run out
    bool checkDeath() {
        return timed ? system_clock::now() - start_time >= lifetime : false;
    }
    // Indicates whether this Entity's onDeath has already been processed
    bool checkAlreadyDied() { return alreadyDied; }

    // Declares a pure virtual onDeath fucntion in order to ensure that
    // it is implemented only in derived entity classes.
    virtual void onDeath(Player* player, std::vector<Entity*>& entity_list) = 0;

    char getIcon() { return icon; }
};

class Bomb : public Entity {
   public:
    void onDeath(Player* player, std::vector<Entity*>& entity_list);

    // Takes position of player or entity in consideration
    // Returns whether the player or entity is in range of the explosion
    bool inRange(Pos p);

    Bomb(Pos p, int bomb_power) : bomb_power(bomb_power) {
        this->position = p;
        this->start_time = system_clock::now();
    }

   private:
    static constexpr duration<double> lifetime = seconds(3);
    static constexpr char icon = 'O';
    int bomb_power = 1;
};

class PowerUp : public Entity {
   public:
    void onDeath(Player* player, std::vector<Entity*>& entity_list) {
        this->alreadyDied = true;
    }
    int getPower() { return this->power; }

   protected:
    static constexpr int power = 0;
    static constexpr duration<double> lifetime = seconds(15);
};
class Healing : public PowerUp {
   public:
    Healing(Pos p) {
        this->position = p;
        this->start_time = system_clock::now();
    }

   protected:
    static constexpr int power = 1;
    static constexpr char icon = 'H';
};
class BombPower : public PowerUp {
   public:
    BombPower(Pos p) {
        this->position = p;
        this->start_time = system_clock::now();
    }

   protected:
    static constexpr int power = 2;
    static constexpr char icon = '!';
};

class Barricade : public Entity {
   public:
    Barricade(Pos p) {
        this->position = p;
        this->timed = false;
    }
    void onDeath(Player* player, std::vector<Entity*>& entity_list) {
        this->alreadyDied = true;
    }

   protected:
    static constexpr char icon = 'X';
};

#endif
