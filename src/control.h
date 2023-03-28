// control.h

#ifndef CONTROL_H
#define CONTROL_H

enum class Input {
    // Directions
    up,
    down,
    left,
    right,

    place,  // Place bomb

    none  // No input
};
Input getInput();

#endif
