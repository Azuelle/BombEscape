//map.h

#ifndef MAP_H
#define MAP_H

#include <vector>
#include <string>
// #include "entity.h"

class Map {
  public:
    Map();
    ~Map();
    void loadMap(const std::string &filename, int size_x, int size_y);
    // vector<Entity> map_objects;
    static int map_arr[15][15];
};

#endif
