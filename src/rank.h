// rank.h

#ifndef RANK_H
#define RANK_H

#include <unistd.h>

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "io_utils.h"

const std::vector<std::pair<std::string, int>> defaultRank{
    {"Jonathan", 6600}, {"Azuelle", 5300}, {"Noel", 5500}, {"Marvolo", 10000}};

// Create a default ranklist.txt
void createDefaultRanklist();

// To get rank from ranklist.txt
// return a vector pair containing the username and score.
std::vector<std::pair<std::string, int>> getRank();

// Add the current record to the ranklist
void addRank(long long score);

#endif
