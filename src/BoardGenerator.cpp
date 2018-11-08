#include "BoardGenerator.h"
#include <algorithm>
#include <random>

Board random_board()
{
    Board board { std::vector<Cell>(), 9 };
    std::fill_n(std::back_inserter(board.cells), 81, Cell { CellStatus::Covered });
    const auto& cells = board.cells;
    std::vector<int> bomb_indices(cells.size());
    std::iota(std::begin(bomb_indices), std::end(bomb_indices), 0);
    std::shuffle(std::begin(bomb_indices), std::end(bomb_indices), std::random_device());
    bomb_indices.resize(2);
    for (int bomb_index : bomb_indices)
        board.cells[bomb_index] = Cell { CellStatus::CoveredAndBomb };
    return board;
}
