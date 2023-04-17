// entity.h

#ifndef ENTITY_H
#define ENTITY_H

#include <chrono>
#include <cmath>
#include <list>

using namespace std::chrono;

// For storing position (a pair of x, y coordinates) and easy calculations
struct Pos {
    int x;
    int y;

    // Return the Manhattan distance between two points
    int distance(Pos to) { return abs(to.x - this->x) + abs(to.y - this->y); }

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
};

#include "player.h"

// A base class for all kinds of non-player entities on the playfield
class Entity {
   private:
    Pos position;
    time_point<system_clock> start_time;
    duration<double> lifetime;
    // Indicates whether this Entity's onDeath has already been processed
    bool alreadyDied = false;
    // Indicates whether this Entity dies after a certain amount of time
    bool timed = true;

   public:
    Entity(duration<double> lifetime, Pos position, bool timed = true)
        : lifetime(lifetime), position(position), timed(timed) {
        start_time = system_clock::now();
    };

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
    virtual void onDeath(Player* player, std::list<Entity>& entity_list) = 0;
};

// TODO: Implementation
class Bomb : Entity {};  // length

// TODO: Implementation
class PowerUp : Entity {
   public:
    void onDeath(Player* player, std::list<Entity>& entity_list) {
        // TODO: Implementation
    }
};

// TODO: Implementation
class Barricade : Entity {};

#endif
