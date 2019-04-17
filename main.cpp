#include <iostream>
#include "connect4game.h"
using namespace std;

int main()
{
    std::cout << "Hello World\n";
    Connect4Game board;
    int player = 1;

    cout << "Test 1: filling up board with alternating pieces\n";
    for (int turn = 0; turn < 42; turn++){
        cout<<"Turn " << turn << "\n";
        board.dropPiece(player,turn%7);
        board.printBoard();
        player *= -1;
    }
    cout << board.getConnectedReds();
    board.clearBoard();
    cout << "Test 2: Randomly playing 100 turns\n";
    for (int turn = 0; turn < 100; turn++){
        cout<<"Turn " << turn << "\n";
        board.makeRandomMove(player);
        board.printBoard();
        player *= -1;
    }

    return 0;
}