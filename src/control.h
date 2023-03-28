// control.h

#ifndef CONTROL_H
#define CONTROL_H

enum class input {
    // Directions
    up,
    down,
    left,
    right,

    place,  // Place bomb

    none  // No input
};
input getInput();

#endif
