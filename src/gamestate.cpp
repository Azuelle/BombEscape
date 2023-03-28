// gamestate.cpp

#include "gamestate.h"

bool Message::finished() {
    return std::chrono::system_clock::now() - start > duration;
}
