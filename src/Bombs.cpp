#include "Bombs.h"
#include "Cells.h"
#include <numeric>
#include <algorithm>

bool is_bomb(const Board& board, Position position)
{
    return cell_at(board, position).status == CellStatus::CoveredAndBomb;
}

Position advance(Position center, int direction)
{
    return {
        center.x + (direction % 3) - 1,
        center.y + (direction / 3) - 1
    };
}

std::vector<Position> moore_neighborhood(const Board& board, Position position)
{
    std::vector<int> range(9);
    std::iota(std::begin(range), std::end(range), 0);
    std::vector<Position> positions(9);
    std::transform(std::cbegin(range), std::cend(range), std::begin(positions), [&position](int i) {
        return advance(position, i);
    });
    auto middle_cell = std::begin(positions);
    std::advance(middle_cell, 4);
    positions.erase(middle_cell);
    return positions;
}

int count_bombs(const Board& board, Position position)
{
    const auto neighbors = moore_neighborhood(board, position);
    return std::count_if(std::begin(neighbors), std::end(neighbors), [&board](Position position) {
        return is_bomb(board, position);
    });
}
