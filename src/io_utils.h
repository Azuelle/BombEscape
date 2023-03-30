// io_utils.h

#ifndef CONTROL_H
#define CONTROL_H

enum class Input {
    // Directions
    up,     // Up
    down,   // Down
    left,   // Left
    right,  // Right

    place,  // Place bomb

    none  // No input
};
Input getInput();

#endif
