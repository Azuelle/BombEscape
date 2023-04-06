#include <fstream>
#include <iostream>
#include "map.h"

Map::Map() {}

Map::~Map() {}

void Map::loadMap(const std::string &filename, int size_x, int size_y) {
  char tile;
  std::ifstream map_file;
  map_file.open(filename);

  for (int y=0, i=0; y < size_y; y++, i++){
    for (int x=0, j=0; x < size_x; x++, j++){
      map_file.get(tile);
      int int_tile = atoi(&tile); //Convert string to int
      map_arr[i][j] = int_tile;
    }
  }

  map_file.close();
  for (int i=0; i<15; i++){
    for (int j=0; j<15; j++){
      std::cout << Map::map_arr[i][j] << "\n"[j == 14];
    }
  }
}
