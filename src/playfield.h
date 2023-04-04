// playfield.h

#ifndef PLAYFIELD_H
#define PLAYFIELD_H

#include <chrono>
#include <cmath>
#include <vector>

#include "player.h"

// For storing position (a pair of x, y coordinates) and easy calculations
struct Position {
    int x;
    int y;

    // Return the Manhattan distance between two points
    int distance(Position to) {
        return abs(to.x - this->x) + abs(to.y - this->y);
    }

    Position(int x, int y) : x(x), y(y) {}
};

// A base class for all kinds of non-player entities on the playfield
class Entity {
   private:
    Position position;
    std::chrono::time_point<std::chrono::system_clock> start_time;
    std::chrono::duration<double> lifetime;
    // Indicates whether this Entity's onDeath has already been processed
    bool alreadyDied = false;

   public:
    Entity(std::chrono::duration<double> lifetime, Position position)
        : lifetime(lifetime), position(position) {
        start_time = std::chrono::system_clock::now();
    };

    Position getPosition() { return this->position; };

    // Checks whether this Entity's timer has run out
    bool checkDeath();
    // Indicates whether this Entity's onDeath has already been processed
    bool checkAlreadyDied();

    // Declares a pure virtual onDeath fucntion in order to ensure that
    // it is implemented only in derived entity classes.
    virtual void onDeath(Player* player, Playfield* playfield) = 0;
};

// TODO: Implementation
class Bomb : Entity {};

// TODO: Implementation
class PowerUp : Entity {};

// TODO: Implementation
class Barricade : Entity {};

// TODO: Implementation
class Playfield {
    // A list of items, bombs, etc. on map
    // These should also have their own classes probably
    // Maybe a seperate header?
};

#endif
