#include <iostream>
#include "minimaxalphabeta.h"
#include "MinimaxAB.h"

using namespace std;

int main()
{
    AB::MiniMaxAB board;
    int choice;
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
   //alpha beta
    }
    else
    {
        cout<<"Invalid choice";
        exit(0);
    }
    return 0;
}
