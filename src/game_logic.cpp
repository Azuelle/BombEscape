// game_logic.cpp

#include "game_logic.h"

#include <vector>

bool quitting = false;

bool checkRunning() { return !quitting; }

void logic(GameState &state, Win w) {
    Input usr_input = getInput(w);
    switch (state.type) {
        case StateType::exit:
            quitting = true;
            break;

        case StateType::alive:
            // Sanity check: Init if player or playfield hasn't been initialized
            if (state.player == nullptr) state.player = new Player(1, 1);
            if (state.playfield == nullptr)
                state.playfield = new Playfield(30, 14);

            // Check for movement
            if (int(Input::up) <= int(usr_input) &&
                int(usr_input) <= int(Input::right))
                movePlayer(state, usr_input);

            // Update Entities
            updateEntityList(state);

            // Check for placing bomb
            if (usr_input == Input::place) placeBomb(state);

            // Display
            display(state, w);

            // Check player health
            if (!state.player->isAlive()) state.type = StateType::death_screen;
            break;

        case StateType::death_screen:
            // TODO: Death screen
            state.type = StateType::main_menu;  // We'll just return to menu for
                                                // now, to be changed
            break;

        case StateType::main_menu:
            int choice = runMenu(w);
            switch (choice) {
                case 0:  // start game
                    state.type = StateType::alive;
                    break;
                case 1:  // ranking

                    break;
                case 2:  // settings

                    break;
                case 3:  // exit
                    state.type = StateType::exit;
                    break;
            }
            break;
    }
}

// IN-GAME LOGICS

// 4 movement directions represented in coordinate offsets
const Pos movement[4] = {
    {0, -1},  // Up
    {0, 1},   // Down
    {-1, 0},  // Left
    {1, 0}    // Right
};

/**
 * Handles what happens when player run into an entity.
 * Default response is to do nothing and block movement.
 */
template <typename T>
void entityInteraction(T *entity, GameState &state, const Pos movement) {}
template <>
void entityInteraction(BombPower *power_up, GameState &state,
                       const Pos movement) {
    state.player->usePowerUp(*power_up);
    state.player->move(movement);
}
template <>
void entityInteraction(Healing *power_up, GameState &state,
                       const Pos movement) {
    state.player->usePowerUp(*power_up);
    state.player->move(movement);
}
template <>
void entityInteraction(Bomb *bomb, GameState &state, const Pos movement) {
    if (!state.playfield->isObstacle(bomb->getPosition() + movement) &&
        state.playfield->locateEntityAt(bomb->getPosition() + movement) ==
            nullptr) {
        bomb->move(movement);
        state.player->move(movement);
    }
}

// Process the movement of player character
void movePlayer(GameState &state, const Input usr_input) {
    Pos destination = state.player->getPosition() + movement[int(usr_input)];
    // Check if player is trying to enter an inaccessible tile
    if (state.playfield->isObstacle(destination)) return;

    Entity *entity_encounter = state.playfield->locateEntityAt(destination);
    // Check if player runs into an entity
    if (!entity_encounter) {
        state.player->setPosition(destination);
        return;
    } else {
        entityInteraction(entity_encounter, state, movement[int(usr_input)]);
    }
}

void updateEntityList(GameState &state) {
    auto *entities = &state.playfield->entity_list;
    for (auto entity : *entities)
        if (entity->checkDeath() && !entity->checkAlreadyDied())
            entity->onDeath(state.player, *entities);

    // delete all the death entities
    std::vector<Entity *> newentitylist;
    for (auto itr = entities->begin(); itr != entities->end(); itr++)
        if (!(*itr)->checkAlreadyDied()) newentitylist.push_back(*itr);
    *entities = newentitylist;
}

// Validates, then place the bomb
void placeBomb(GameState &state) {
    if (state.player->canPlaceBomb()) {
        state.playfield->entity_list.push_back(new Bomb(
            state.player->getPosition(), state.player->getBombPower(), true));
        state.player->setBombPlaced(true);
    }
}
