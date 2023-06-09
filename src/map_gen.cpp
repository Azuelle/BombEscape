// mapgen.cpp

#include "map_gen.h"

#include <cstring>
#include <deque>
#include <random>
#include <vector>

using namespace std;

// Add a wall border to the map
vector<deque<bool>> addBorder(vector<deque<bool>> map) {
    int width = map[0].size();
    for (auto& line : map) {
        line.push_front(true);
        line.push_back(true);
    }
    map.insert(map.begin(), deque<bool>(width + 2, true));
    map.push_back(deque<bool>(width + 2, true));
    return map;
}

// Recursive fill algorithm for checking connectivity
void fill(int x, int y, vector<deque<bool>>& filled) {
    if (filled[y][x]) return;
    filled[y][x] = true;

    if (x > 0) fill(x - 1, y, filled);
    if (x < int(filled[0].size()) - 1) fill(x + 1, y, filled);
    if (y > 0) fill(x, y - 1, filled);
    if (y < int(filled.size()) - 1) fill(x, y + 1, filled);
}

// Verify the validity of a map with fill
bool verifyMap(const vector<deque<bool>>& map) {
    int width = map[0].size(), height = map.size();
    if (map[0][0] || map[height - 1][width - 1]) return false;

    vector<deque<bool>> filled = addBorder(map);
    fill(1, 1, filled);
    if (filled[height][width]) return true;
    return false;
}

vector<deque<bool>> generateMap(int width, int height, int seed) {
    // Predesignate space for outer ring of walls
    width -= 2;
    height -= 2;

    default_random_engine rng(seed);
    uniform_int_distribution<int> dist(0, 1);

    vector<deque<bool>> current(height, deque<bool>(width, false));
    vector<deque<bool>> last_viable(current);

    // Add longer walls
    for (int i = 0; i < width * height / 10; i++) {
        bool is_vertical = dist(rng);
        int length = dist(rng) + 2;

        uniform_int_distribution<int> getStartX(
            0, width - (is_vertical ? 1 : length));
        uniform_int_distribution<int> getStartY(
            0, height - (is_vertical ? length : 1));
        int start_x = getStartX(rng);
        int start_y = getStartY(rng);

        for (int j = 0; j < length; j++)
            current[start_y + (is_vertical ? j : 0)]
                   [start_x + (is_vertical ? 0 : j)] = true;
        if (verifyMap(current))
            last_viable = current;
        else {
            current = last_viable;
            --i;
        }
    }

    // Add scattered walls
    for (int i = 0; i < width * height / 20; i++) {
        uniform_int_distribution<int> getX(0, width - 1);
        uniform_int_distribution<int> getY(0, height - 1);
        current[getY(rng)][getX(rng)] = true;
        if (verifyMap(current))
            last_viable = current;
        else {
            current = last_viable;
            --i;
        }
    }

    return addBorder(last_viable);
}
vector<deque<bool>> generateMap(int width, int height) {
    random_device rd;
    return generateMap(width, height, rd());
}
