// mapgen.h

#ifndef MAPGEN_H
#define MAPGEN_H

#include <deque>
#include <vector>

// Randomly generate a map while ensuring connectivity
std::vector<std::deque<bool>> generateMap(int width, int height, int seed);
std::vector<std::deque<bool>> generateMap(int width, int height);

#endif
