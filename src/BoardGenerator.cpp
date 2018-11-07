#include "BoardGenerator.h"
#include <algorithm>
#include <random>

Board random_board()
{
    Board board;
    board.width = 3;
    std::fill_n(std::back_inserter(board.cells), 9, Cell { CellStatus::Covered });
    const auto& cells = board.cells;
    std::vector<int> bomb_indices(cells.size());
    std::shuffle(std::begin(bomb_indices), std::end(bomb_indices), std::mt19937(std::random_device()));
    return board;
}
