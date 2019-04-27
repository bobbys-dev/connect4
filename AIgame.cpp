#include "AIgame.h"
#include<iostream>
using namespace std;
using namespace AI;



void AIgame::MinmaxVsAlphabeta(int depth,int peice)
{
    //Here Minmax is max player and AlphaBeta is min player
    MiniMaxAB temp;
    int m;
    bool win;

    for(m=0;m<22;m++)
    {
        //***********Minmax Logic begins**************************************************
        MiniMaxAB temp;
        int m,columnNumber,pass[6][7];
        bool win;
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
        win=checkWinBoard(board);
        if(win)
        {
            cout<<"******Game Over*******"<<endl;
            break;
        }
        //***********Minmax Logic ends**************************************************

        //***********Alphabeta Logic begins**************************************************
        peice=-1;
        cout<<"\nYour turn, enter the column number you want to drop the coin:\n";
        cin>>columnNumber;
        this->board.dropPiece(peice,columnNumber);
         cout<<"\nThe board position after your(Human) turn is"<<endl;
        this->board.printBoard();
        checkWinBoard(board);
        //***********Alphabeta Logic ends**************************************************
    }
}

