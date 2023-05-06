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
using namespace std;

// Return user's key setting;
// If exists error, return a default setting. 
map<string,int> config();

#endif
