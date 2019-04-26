#include <iostream>
#include "minimaxalphabeta.h"
#include "MinimaxAB.h"

using namespace std;

int main()
{
    //AI::MiniMaxAB session;
    AI::AlphaBeta session;
    int choice;
    cout<<"\nCONNECT FOUR GAME"<<endl;
    cout<<"\nEnter the mode from the following:\n1.Human vs Computer(MinimaxAB)\n2.Human vs Computer(AlphaBeta)\n";
    //cin>>choice;
    choice = 2;
    session.clearGameBoard();
    cout<<"\nInitial Board Position\n";
    session.printGameBoard();
    if(choice==1)
    {
        cout<<"\nComputer turn..."<<endl;
        //session.humanVsComputerMinimaxAB(0,1);

    }
    else if(choice==2)
    {
   //alpha beta
        int depth = 2;
        session.humanVsComputerAlphaBeta(depth,1);
    }
    else
    {
        cout<<"Invalid choice";
        exit(0);
    }
    return 0;
}
