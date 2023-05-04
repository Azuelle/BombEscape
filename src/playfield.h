// playfield.h

#ifndef PLAYFIELD_H
#define PLAYFIELD_H

#include <chrono>
#include <cmath>
#include <vector>

#include "entity.h"

// TODO: Implementation
class Playfield {
    // A list of items, bombs, etc. on map
    // These should also have their own classes probably
    // Maybe a seperate header?
   private:
    int width;
    int height;

   public:
    Playfield(int width, int height, std::vector<std::vector<bool>> wall)
        : width(width), height(height), wall(wall) {}

    std::vector<Entity*> entity_list;
    // True: wall False: no wall
    std::vector<std::vector<bool>> wall;

    /**
     * Checks if a tile is accessible
     * Has wall: return true
     */
    bool isObstacle(Pos pos);

    /**
     * Locates the entity at a certain position.
     * Takes the coordinate of the target tile.
     * Returns a pointer to such entity if found.
     * Returns nullptr if not found.
     */
    Entity* locateEntityAt(Pos pos) {
        for (auto en : entity_list)
            if (en->getPosition() == pos) return en;
        return nullptr;
    }
};

#endif
