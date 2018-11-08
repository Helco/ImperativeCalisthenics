#include "BoardReveal.h"
#include "Bombs.h"
#include "Cells.h"
#include <algorithm>
#include <iostream>

Board uncover_at(const Board& old_board, Position position);

Board uncover_neighbors(const Board& old_board, Position position)
{
    auto neighbors = moore_neighborhood(old_board, position);
    neighbors.erase(std::remove_if(std::begin(neighbors), std::end(neighbors), [&old_board, position](Position neighbor_position) {
        Cell neighbor_cell = cell_at(old_board, position);
        return neighbor_cell.status != CellStatus::Uncovered;
    }));
    auto board = old_board;
    for (Position covered_cell : neighbors)
        board = uncover_at(board, covered_cell);
    return board;
}

Board uncover_at(const Board& old_board, Position position)
{
    if (!is_valid(old_board, position))
        return old_board;
    auto board = old_board;
    int bomb_count = count_bombs(old_board, position);
    if (bomb_count == 0)
        board = uncover_neighbors(board, position);
    int index = index_of(board, position);
    board.cells[index] = Cell { CellStatus::Uncovered };
    return board;
}

RevealResult reveal_at(const Board& old_board, Position position)
{
    RevealResult result = { old_board, std::nullopt };
    if (is_bomb(old_board, position))
    {
        result.second = std::make_optional("Boom");
        return result;
    }
    result.first = uncover_at(old_board, position);
    return result;
}
