// config.h

#ifndef CONFIG_H
#define CONFIG_H

#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

#include "io_utils.h"

const std::map<std::string, int> defaultConfig = {
    {"up", 259},   {"down", 258},   {"left", 260},     {"right", 261},
    {"place", 32}, {"confirm", 10}, {"backspace", 263}};

// List of required keys
const std::vector<std::string> necessaryKeys = {
    "up", "down", "left", "right", "place", "confirm", "backspace"};

inline void createDefaultConfigFile();

// Return user's key setting;
// If exists error, return a default setting.
std::map<std::string, int> getConfig();

#endif
