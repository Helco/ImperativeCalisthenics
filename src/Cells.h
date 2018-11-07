#pragma once
#include "Board.h"
#include "Position.h"

Cell cell_at(const Board& board, Position position);
bool valid_position(const Board& board, Position position);
int index_of(const Board& board, Position position);
