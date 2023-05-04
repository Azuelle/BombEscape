// game_logic.cpp

#include "game_logic.h"

#include <vector>

#include "playfield.h"
void logic(GameState &state) {
    switch (state.type) {
        case StateType::exit:
            quitting = true;
            break;
        case StateType::alive:
            Input usr_input = getInput();
            if (int(Input::up) <= int(usr_input) <= int(Input::right))
                movePlayer(state, usr_input);
            break;
        case StateType::death_screen:

            break;
        case StateType::main_menu:

            break;
    }
}

// IN-GAME LOGICS

// 4 movement directions represented in coordinate offsets
const Pos movement[4] = {
    {0, 1},   // Up
    {0, -1},  // Down
    {1, 0},   // Left
    {-1, 0}   // Right
};

/**
 * Handles what happens when player run into an entity.
 * Default response is to do nothing and block movement.
 */

template <typename T>
void entityInteraction(T *entity, GameState &state, const Pos movement) {}
template <>
void entityInteraction(PowerUp *power_up, GameState &state,
                       const Pos movement) {
    // TODO: Handle power-ups
}
template <>
void entityInteraction(Bomb *bomb, GameState &state, const Pos movement) {
    if (movement.x == 0 && movement.y == 1) {  // up
        if (state.playfield->isObstacle(bomb->getPosition())) {
            return;

            bomb->setPosition(bomb->getPosition() + movement);
        }
        if (movement.x == 0 && movement.y == -1) {  // down
            if (state.playfield->isObstacle(bomb->getPosition())) {
                return;
            }

            bomb->setPosition(bomb->getPosition() + movement);
        }
        if (movement.x == 1 && movement.y == 0) {  // left
            if (state.playfield->isObstacle(bomb->getPosition())) {
                return;
            }

            bomb->setPosition(bomb->getPosition() + movement);
        }
        if (movement.x == -1 && movement.y == 0) {  // right
            if (state.playfield->isObstacle(bomb->getPosition())) {
                return;
            }

            bomb->setPosition(bomb->getPosition() + movement);
        }
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
            entity.onDeath(state.player, *entities);

    // delete all the death entities
    std::vector<Entity *> newentitylist;
    for (auto itr = entities->begin(); itr != entities->end(); itr++)
        if (!(*itr)->checkAlreadyDied()) newentitylist.push_back(*itr);
    *entities = newentitylist;
}

bool checkRunning() { return !quitting; }

void placeBomb(GameState &state) {  // placebomb
    state.playfield->entity_list.push_back(Bomb());
    Bomb->setPosition(state.player->getPosition());
}
