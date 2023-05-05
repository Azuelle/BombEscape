// playfield.h

#ifndef PLAYFIELD_H
#define PLAYFIELD_H

#include <chrono>
#include <cmath>
#include <deque>
#include <vector>

#include "entity.h"

// For storing walls, entities and providing related functionalities
class Playfield {
   private:
    int width;
    int height;

   public:
    Playfield(int width, int height, std::vector<std::deque<bool>> wall)
        : width(width), height(height), wall(wall) {}

    std::vector<Entity*> entity_list;

    // True: wall  False: no wall
    std::vector<std::deque<bool>> wall;

    int getWidth() { return width; }
    int getHeight() { return height; }

    /**
     * Checks if a tile is accessible
     * Has wall: return true
     */
    bool isObstacle(Pos pos) { return wall[pos.y][pos.x]; }
    bool isObstacle(int x, int y) { return wall[x][y]; }

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
