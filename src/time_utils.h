// time_utils.h

#ifndef TIME_UTILS_H
#define TIME_UTILS_H

#include <chrono>

using namespace std::chrono;

static const int FRAMES_PER_SECOND = 30;
static microseconds const FRAME_TIME =
    seconds(1) / FRAMES_PER_SECOND;  // Length of a frame

#endif
