// time_utils.h

#ifndef TIME_UTILS_H
#define TIME_UTILS_H

#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <string>

using namespace std::chrono;

static const int FRAMES_PER_SECOND = 30;
static microseconds const FRAME_TIME =
    seconds(1) / FRAMES_PER_SECOND;  // Length of a frame

std::string getCurrentTimeAndDate();

#endif
