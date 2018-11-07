#pragma once
#include "Board.h"
#include "Position.h"

std::vector<Cell> moore_neighborhood(const Board& board, Position position);
int count_bombs(const Board& board, Position position);
