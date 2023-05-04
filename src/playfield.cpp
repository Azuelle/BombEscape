#include "playfield.h"

bool Playfield::isObstacle(Pos pos) { 
    if (wall[pos.y][pos.x] == true){
        return wall[pos.y][pos.x];
    }
    else{
        return false;
    }
}

