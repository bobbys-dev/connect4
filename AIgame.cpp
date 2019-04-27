#include "AIgame.h"
#include<iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;
using namespace AI;

static int gamePath=0;
static int totalNodes=0;
static int executionTime=0;

void AIgame::MinmaxVsAlphabeta(int depth,int peice)
{
    MiniMaxAB temp;
    int m;
    bool win;
    AlphaBeta alphabeta_session;
    some_struct alphabeta_search_result; //for alphabeta search results
    this->gameState.setDepthPlayed(0); //set search depth for alphabeta
    int memorySize,nodeSize=43;

    for(m=0;m<22;m++)
    {
        //***********Minmax Logic begins*********************************
        MiniMaxAB temp;
        int m,columnNumber,pass[6][7];
        bool win=false;
        peice=-1;
        bestPathMinmaxAB.clear();
        auto start = high_resolution_clock::now();
        temp = miniMaxSearch(board,depth,peice,100,-120);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        executionTime+=duration.count();
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
            cout<<"\nTotal length of the game: "<<gamePath;
            cout<<"\nTotal number of nodes generated and expanded are: "<<totalNodes+1;
            memorySize=(temp.totalNodes+1)*nodeSize;
            cout<<"\nThe size of memory used by the program: "<<memorySize;
            cout <<"\nExecution time: "<< executionTime << endl;
            break;
        }

        //***********Minmax Logic ends***********************************

        //***********Alphabeta Logic begins******************************
        peice=1;
        win=false;
        start = high_resolution_clock::now();
        alphabeta_search_result = alphaBetaSearch(this->board,peice,depth);
        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);
        executionTime+=duration.count();
        this->board.dropPiece(peice, this->bestPath.back());
        this->board.printBoard();
        gamePath++;
        win=checkWinBoard(board);
        if(win)
        {
            cout<<"\nAlphaBeta methodology won! \n GAME OVER"<<endl;
            cout<<"\nTotal length of the game: "<<gamePath;
            cout<<"\nTotal number of nodes generated and expanded are: "<<totalNodes+1;
            memorySize=(totalNodes+1)*nodeSize;
            cout<<"\nThe size of memory used by the program: "<<memorySize;
            cout <<"\nExecution time: "<< executionTime << endl;
            break;
        }
        //***********Alphabeta Logic ends********************************
    }
}

