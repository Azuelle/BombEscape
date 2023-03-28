// gamestate.h

#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <chrono>
#include <map>
#include <queue>
#include <string>
#include <vector>

// Describes the type of state a gamestate is in
enum class StateType {
    main_menu,
    // In-game
    alive,
    // Player has died and is being shown the death screen (with
    // scores, etc.)
    death_screen,

    // etc., add as needed
};

// Describes the type of a message
// Will determine where on the UI the message will display
enum class MessageType {
    // Not set, message will not be displayed
    none,
    // Warning / Error
    err,
    // Game tips (spawning / acquiring items, high score, etc.)
    tips,
};

// Pop-up on-screen messages
// Sorted by start time
// New message would overwrite existing ones
class Message {
   public:
    Message(std::string content, std::chrono::duration<double> duration)
        : content(content), duration(duration) {
        start = std::chrono::system_clock::now();
    }

    // Returns true if the message has been displayed for long enough
    bool finished();

    bool Message::operator<(Message operand) { return start < operand.start; }
    bool Message::operator>(Message operand) { return start > operand.start; }

   private:
    std::string content;

    std::chrono::duration<double> duration;
    std::chrono::time_point<std::chrono::system_clock> start;
    MessageType type;
};

// Stores the game's state at a certain moment
class GameState {
   public:
    GameState();
    ~GameState();

    StateType state = StateType::main_menu;

   private:
    std::chrono::time_point<std::chrono::system_clock> start_time;
};

#endif
