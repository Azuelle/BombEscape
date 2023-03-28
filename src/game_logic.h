// game_logic.h

#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

#include "control.h"
#include "gamestate.h"

void logic(GameState cur_state, Input usr_input);
bool checkRunning();

#endif
