#include <iostream>
#include "minimaxalphabeta.h"
#include "MinimaxAB.h"

using namespace std;

int main()
{
    //AB::MiniMaxAB board; // Correction: minmax AB is a playing session, not a board
    AB::MiniMaxAB session;
    int choice;
    cout<<"\nCONNECT FOUR GAME"<<endl;
    cout<<"\nEnter the mode from the following:\n1.Human vs Computer(MinimaxAB)\n2.Human vs Computer(AlphaBeta)\n";
    cin>>choice;
    session.clearGameBoard();
    cout<<"\nInitial Board Position\n";
    session.printGameBoard();
    if(choice==1)
    {
        cout<<"\nComputer turn..."<<endl;
        session.humanVsComputerMinimaxAB(0,1); // Correction: the session already has an internal board and you
        //only need to pass a board when calling miniMaxAB(), not humanvsCPU
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
