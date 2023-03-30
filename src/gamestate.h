// gamestate.h

#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <chrono>
#include <vector>

#include "player.h"
#include "playfield.h"

/**
 * For describing the type of state a gamestate is in.
 * enum class is used here for simplicity (decrease chance of typo).
 */
enum class StateType {
    main_menu,
    // In-game
    alive,
    // Player has died and is being shown the death screen (with
    // scores, etc.)
    death_screen,

    // etc., add as needed
};

// Stores the game's state at a certain moment
class GameState {
   public:
    GameState();
    ~GameState();

    StateType getState() { return this->state; }
    // Returns false if unsuccessful (already at this state)
    bool setState(StateType target);

   private:
    std::chrono::time_point<std::chrono::system_clock> start_time;
    StateType state = StateType::main_menu;
    Player *player = nullptr;
    Playfield *playfield = nullptr;
};

#endif
