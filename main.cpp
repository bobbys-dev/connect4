#include <iostream>
#include "minimaxalphabeta.h"
#include "MinimaxAB.h"

using namespace std;
using namespace AI;
int main()
{

    int choice;
    cout<<"\nCONNECT FOUR GAME"<<endl;
    cout<<"\nEnter the mode from the following:\n1.Human vs Computer(MinimaxAB)\n2.Human vs Computer(AlphaBeta)\n";
    cin>>choice;

    if(choice==1)
    {
        MiniMaxAB minimaxab_session;
        minimaxab_session.clearGameBoard();
        cout<<"\nComputer's turn..."<<endl;
        minimaxab_session.humanVsComputerMinimaxAB(0,1);
    }
    else if(choice==2)
    {
   //alpha beta
      AlphaBeta alphabeta_sesssion;
      int depth = 1;
      alphabeta_sesssion.humanVsComputerAlphaBeta(depth,1);
    }
    else
    {
        cout<<"Invalid choice";
        exit(0);
    }
    
    return 0;
}
