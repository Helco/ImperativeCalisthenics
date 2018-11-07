#include "Cells.h"
#include <iterator>
#include <algorithm>

int index_of(const Board& board, Position position)
{
    const int width = board.width;
    const int row = position.y * width;
    return row + position.x;
}

bool is_valid(const Board& board, Position position)
{
    const int index = index_of(board, position);
    const int cell_count = std::size(board.cells);
    return (index >= 0 && index < cell_count);
}

Cell cell_at(const Board& board, Position position)
{
    const int index = index_of(board, position);
    if (is_valid(board, position))
    {
        return board.cells[index];
    }
    Cell null_cell;
    null_cell.status = CellStatus::Uncovered;
    return null_cell;
}
