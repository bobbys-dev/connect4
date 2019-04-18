#include <iostream>
#include "connect4game.h"
#include "MinimaxAB.h"
using namespace std;

int main()
{
    AB::MiniMaxAB board;
    int choice,player;
    cout<<"\nCONNECT FOUR GAME"<<endl;
    cout<<"\nEnter the mode from the following:\n1.Human vs Computer(MinimaxAB)\n2.Human vs Computer(AlphaBeta)\n";
    cin>>choice;
    board.clearGameBoard();
    cout<<"\nInitial Board Position\n";
    board.printGameBoard();
    if(choice==1)
    {
        cout<<"\nComputer turn..."<<endl;
        board.humanVsComputerMinimaxAB(board,0,1);
    }
    else if(choice==2)
    {
        //AlphaBetaCode
    }
    else
    {
        cout<<"Invalid choice";
        exit(0);
    }
//    cout << "Test 1: filling up board with alternating pieces\n";
//    for (int turn = 0; turn < 42; turn++)
//    {
//        cout<<"Turn " << turn << "\n";
//        board.dropPiece(player,turn%7);
//        board.printBoard();
//        player *= -1;
//    }
//    cout << board.getConnectedReds();
//    board.clearBoard();
//    cout << "Test 2: Randomly playing 100 turns\n";
//    for (int turn = 0; turn < 100; turn++)
//    {
//        cout<<"Turn " << turn << "\n";
//        board.makeRandomMove(player);
//        board.printBoard();
//        player *= -1;
//    }

    return 0;
}
