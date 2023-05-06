// message.h

#ifndef MESSAGE_H
#define MESSAGE_H

#include <chrono>
#include <string>

using namespace std::chrono;

/**
 * Pop-up on-screen messages.
 * Sorted by start time.
 */
class Message {
   public:
    Message(std::string content, duration<double> duration)
        : content(content), display_length(duration) {
        start = system_clock::now();
    }
    Message(std::string type, std::string content, duration<double> duration)
        : type(type), content(content), display_length(duration) {
        start = system_clock::now();
    }

    // Returns true if the message has been displayed for long enough
    bool finished() { return system_clock::now() - start > display_length; };

    friend bool operator<(const Message &a, const Message &b) {
        return a.start < b.start;
    }
    friend bool operator>(const Message &a, const Message &b) {
        return a.start > b.start;
    }

   private:
    // Type of the message
    // Should always be Capitalized.
    std::string type = "None";
    // Content of the message
    std::string content;

    duration<double> display_length;
    time_point<system_clock> start;
};

#endif
