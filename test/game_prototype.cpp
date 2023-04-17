#include <unistd.h>

#include <chrono>
#include <cstdio>
#include <iostream>

#include "../src/time_utils.h"

using namespace std::chrono;

bool wall[10][10] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 1, 1, 1, 1, 0, 0, 1},
    {1, 0, 0, 1, 0, 0, 1, 0, 0, 1}, {1, 0, 0, 1, 0, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 1, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

int pl_x = 2, pl_y = 2, pl_hp = 3;

int b_x = -1, b_y = -1;
bool b_placed = false;
time_point<system_clock> b_start;

duration<double> B_LEN = seconds(5);
int B_SIZE = 3;

void print() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++)
            if (i == pl_y && j == pl_x)
                std::cout << "@ ";
            else if (b_placed && i == b_y && j == b_x)
                std::cout << "O ";
            else
                std::cout << (wall[i][j] ? "# " : ". ");
        std::cout << std::endl;
    }
    std::cout << "HP " << pl_hp << std::endl << std::endl;
}

void move(int x, int y) {
    if (!wall[pl_y + y][pl_x + x]) {
        if (!b_placed || pl_x + x != b_x || pl_y + y != b_y ||
            !wall[b_y + y][b_x + x]) {
            pl_x += x;
            pl_y += y;
        }
        if (b_placed && pl_x + x == b_x && pl_y + y == b_y &&
            !wall[b_y + y][b_x + x]) {
            b_x += x;
            b_y += y;
        }
    }
}

void place() {
    if (!b_placed) {
        b_placed = true;
        b_x = pl_x, b_y = pl_y;
        b_start = system_clock::now();
    }
}

void checkExplosion() {
    if (!b_placed || system_clock::now() - b_start < B_LEN) return;
    if ((pl_x == b_x && abs(pl_y - b_y) <= B_SIZE) ||
        (pl_y == b_y && abs(pl_x - b_x) <= B_SIZE))
        pl_hp--;
    b_placed = false;
}

int main() {
    char opr = '\0';
    while (opr != 'q') {
        checkExplosion();
        print();
        opr = getchar();
        switch (opr) {
            case 'w':
                move(0, -1);
                break;
            case 's':
                move(0, 1);
                break;
            case 'a':
                move(-1, 0);
                break;
            case 'd':
                move(1, 0);
                break;
            case 'j':
                place();
        }
        usleep(FRAME_TIME.count());  // Wait until next frame
    }
}
