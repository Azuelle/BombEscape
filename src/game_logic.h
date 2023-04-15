// game_logic.h

#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

#include "gamestate.h"
#include "io_utils.h"

// Process all game logic
void logic(GameState &cur_state, const Input usr_input);

void movePlayer(GameState &cur_state, const Input usr_input);

bool checkRunning();

bool quitting = false;

#endif
