// game_logic.h

#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

#include "gamestate.h"
#include "init_window.h"
#include "io_utils.h"
#include "menu.h"
#include "playfield.h"

// Process all game logic
void logic(GameState &cur_state, Win w);

void movePlayer(GameState &cur_state, const Input usr_input);

bool checkRunning();

#endif
