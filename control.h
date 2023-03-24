// control.h

#ifndef CONTROL_H
#define CONTROL_H

enum class input : bool {
    // Directions
    up = true,
    down = true,
    left = true,
    right = true,

    place = true,  // Place bomb
    none = false   // No input
};
input getInput();

#endif
