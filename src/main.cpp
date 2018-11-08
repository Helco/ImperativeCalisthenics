#include "Board.h"
#include "BoardGenerator.h"
#include "Bombs.h"
#include "BoardReveal.h"
#include <iostream>

int main()
{
    Board board = random_board();
    print(board);

    RevealResult result = reveal_at(board, { 1, 1 });

    std::cout << std::endl;

    print(result.first);

    std::cin.get();
    return 0;
}
