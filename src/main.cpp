#include "Board.h"
#include "BoardGenerator.h"
#include <iostream>

int main()
{
    Board board = random_board();
    print(board);
    std::cin.get();
    return 0;
}
