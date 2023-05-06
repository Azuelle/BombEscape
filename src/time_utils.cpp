// time_utils.cpp

#include "time_utils.h"

// From StackOverflow
// https://stackoverflow.com/a/17223443
std::string getCurrentTimeAndDate() {
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);

    std::stringstream ss;
    ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X");
    return ss.str();
}
