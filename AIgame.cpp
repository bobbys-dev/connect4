#include "AIgame.h"
#include<iostream>
using namespace std;
using namespace AI;

static int gamePath;

void AIgame::MinmaxVsAlphabeta(int depth,int peice)
{
    MiniMaxAB temp;
    int m;
    bool win;
    AlphaBeta alphabeta_session;
    some_struct alphabeta_search_result; //for alphabeta search results
    this->gameState.setDepthPlayed(0); //set search depth for alphabeta

    for(m=0;m<22;m++)
    {
        //***********Minmax Logic begins*********************************
        MiniMaxAB temp;
        int m,columnNumber,pass[6][7];
        bool win=false;
        peice=1;
        bestPathMinmaxAB.clear();
        temp = miniMaxSearch(board,depth,peice,100,-120);
        for(int i=0;i<6;i++)
		{
			for(int j=0;j<7;j++)
			{
				//find child with move 0 and then store it into board
				pass[i][j] = bestPathMinmaxAB[bestPathMinmaxAB.size() -1].board.getSlotValue(i,j);
			}
		}
		setBoard1(pass);
        cout<<"\nThe board position after computer's turn is"<<endl;
        this->board.printBoard();
        gamePath++;
        win=checkWinBoard(board);
        if(win)
        {
            cout<<"\nMinmaxAB methodology won! \n GAME OVER"<<endl;
            cout<<"\nTotal length of the game: "<<gamePath<<endl;
            break;
        }

        //***********Minmax Logic ends***********************************

        //***********Alphabeta Logic begins******************************

        peice=-1;
        win=false;
        alphabeta_search_result = alphaBetaSearch(this->board,peice,depth);
        this->board.dropPiece(peice, this->bestPath.back());
        this->board.printBoard();
        gamePath++;
        win=checkWinBoard(board);
        if(win)
        {
            cout<<"\nAlphaBeta methodology won! \n GAME OVER"<<endl;
            cout<<"\nTotal length of the game: "<<gamePath<<endl;
            break;
        }
        //***********Alphabeta Logic ends********************************
    }
}

