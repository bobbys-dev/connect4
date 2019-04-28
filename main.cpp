#include <iostream>
#include "minimaxalphabeta.h"
#include "MinimaxAB.h"
#include "connect4game.h"
#include "AIgame.h"

using namespace std;
using namespace AI;
int main()
{

    int choice;
    int searchDepth = 1; // change this for different search depth desired
    cout<<"\nCONNECT FOUR GAME"<<endl;
    cout<<"\nEnter the mode from the following:\n1.Human vs Computer(MinimaxAB)\n2.Human vs Computer(AlphaBeta)\n3. Computer(MinmaxAB) vs Computer(Alphabeta)\n4. Computer(MinmaxAB) vs Computer(MinmaxAB)\n5. Computer(Alphabeta) Vs Computer(Alphabeta)\n";
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
      AlphaBeta alphabeta_session;
      alphabeta_session.humanVsComputerAlphaBeta(searchDepth,1);
    }
    else if(choice==3)
    {
        AIgame aiGame_session;
        aiGame_session.MinmaxVsAlphabeta(0,1);
   }
    else if(choice==4)
    {
        AIgame aiGame_session;
        aiGame_session.MinmaxVsMinmax(0,1);
    }
    else if(choice==5)
    {
      AIgame aiGame_session;
      aiGame_session.AlphaBetaVsAlphaBeta(0,1);
    }
    else
    {
        cout<<"Invalid choice";
        exit(0);
    }

    return 0;
}
