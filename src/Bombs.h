#pragma once
#include "Board.h"
#include "Position.h"

bool is_bomb(const Board& board, Position position);
std::vector<Position> moore_neighborhood(const Board& board, Position position);
int count_bombs(const Board& board, Position position);
