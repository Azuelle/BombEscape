// gamestate.h

#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <chrono>
#include <vector>

#include "player.h"
#include "playfield.h"

using namespace std::chrono;

/**
 * For describing the type of state a gamestate is in.
 * enum class is used here for simplicity (decrease chance of typo).
 */
enum class StateType {
    // Quitting the game
    exit,
    // In main menu
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
   private:
    time_point<system_clock> start;

   public:
    GameState() { this->start = system_clock::now(); }
    GameState(Player player, Playfield playfield)
        : player(&player), playfield(&playfield) {
        this->start = system_clock::now();
    }
    ~GameState() { delete this->player, delete this->playfield; }

    Player *player = nullptr;
    Playfield *playfield = nullptr;
    StateType type = StateType::main_menu;

    duration<double> getCurrentDuration() {
        return system_clock::now() - this->start;
    }
};

#endif
