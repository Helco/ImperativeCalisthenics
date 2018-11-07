#include "Bombs.h"
#include "Cells.h"
#include <numeric>
#include <algorithm>

bool is_bomb(const Cell& cell)
{
    return cell.status == CellStatus::CoveredAndBomb;
}

Position advance(Position center, int direction)
{
    return {
        center.x + (direction % 3) - 1,
        center.y + (direction / 3) - 1
    };
}

std::vector<Cell> moore_neighborhood(const Board& board, Position position)
{
    std::vector<int> range(9);
    std::iota(std::begin(range), std::end(range), 0);
    std::vector<Position> positions(9);
    std::vector<Cell> cells(9);
    std::transform(std::cbegin(range), std::cend(range), std::begin(positions), [&position](int i) {
        return advance(position, i);
    });
    std::transform(std::cbegin(positions), std::cend(positions), std::begin(cells), [&board](Position neighbor) -> Cell {
        return cell_at(board, neighbor);
    });
    auto middle_cell = std::begin(cells);
    std::advance(middle_cell, 4);
    cells.erase(middle_cell);
    return cells;
}

int count_bombs(const Board& board, Position position)
{
    const auto& cells = board.cells;
    return std::count_if(std::cbegin(cells), std::cend(cells), is_bomb);
}
