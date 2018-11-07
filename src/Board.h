#pragma once
#include "Cell.h"
#include <vector>

struct Board {
    std::vector<Cell> cells;
    unsigned int width;
};
void print(const Board& board);
