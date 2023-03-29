// gamestate.cpp

#include "gamestate.h"

bool GameState::setState(StateType target) {
    if (this->state != target) {
        this->state = target;
        return true;
    }
    return false;
}
