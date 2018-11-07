#include "Cells.h"
#include "Bombs.h"
#include <iostream>

char count_char(int count)
{
    static const char chars[] = { '.', '1', '2', '3', '4', '5', '6', '7', '8' };
    return chars[count];
}

void print(const Board& board, Position position)
{
    Cell cell = cell_at(board, position);
    int bomb_count = count_bombs(board, position);
    const char cell_texts[] = { '#', '%', count_char(bomb_count)};
    std::cout << cell_texts[static_cast<int>(cell.status)];
}

Position from(const Board& board, int index)
{
    return {
        index % board.width,
        index / board.width
    };
}

void print(const Board& board)
{
    static const std::string end_lines[] = { "", "\n" };
    const int width = board.width;
    int i = 0;
    for (Cell cell : board.cells)
    {
        print(board, from(board, i));
        std::cout << end_lines[(i % width) == width - 1];
        i++;
    }
}
