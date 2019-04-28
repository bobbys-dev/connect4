#include "AIgame.h"
#include<iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;
using namespace AI;

static int gamePath=0;
static int totalNodes=0;
static int executionTime=0;

void AIgame::MinmaxVsAlphabeta(int depth,int piece)
{
    MiniMaxAB temp;
    int m;
    bool win;
    AlphaBeta alphabeta_session;
    alphabeta_session.evalType = -1; // tell alphabeta which eval to run
    some_struct alphabeta_search_result; //for alphabeta search results
    this->gameState.setDepthPlayed(depth); //set search depth for alphabeta
    int memorySize,nodeSize=43;

    for(m=0;m<22;m++)
    {
        //***********Minmax Logic begins*********************************
        MiniMaxAB temp;
        int m,columnNumber,pass[6][7];
        bool win=false;
        piece=-1;
        bestPathMinmaxAB.clear();
        auto start = high_resolution_clock::now();
        cout << "minmax searching..." << endl;
        temp = miniMaxSearch(board,depth,piece,100,-120);
        cout << "..minmax done searching." << endl;
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        executionTime+=duration.count();
        cout << "..minmax entering forloop." << endl;
        for(int i=0;i<6;i++)
		{
			for(int j=0;j<7;j++)
			{
				//find child with move 0 and then store it into board
            cout << "minmax assigning pass for where i, j=" << i << ", " << j << endl;

				pass[i][j] = bestPathMinmaxAB[bestPathMinmaxAB.size() -1].board.getSlotValue(i,j);
			}
		}
      cout << "..minmax exit forloop." << endl;
		setBoard1(pass);
        cout<<"\nThe board after minmax turn is"<<endl;
        this->board.printBoard();
        gamePath++;
        win=checkWinBoard(board);
        if(win)
        {
           cout<<"\nMinmaxAB methodology won! \n GAME OVER"<<endl;
            break; //stop game
        }

        //***********Minmax Logic ends***********************************

        //***********Alphabeta Logic begins******************************
        piece=1;
        win=false;
        start = high_resolution_clock::now();
        cout << "alphabeta searching..." << endl;
        alphabeta_search_result = alphaBetaSearch(this->board,piece,depth);
        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);
        executionTime+=duration.count();
        this->board.dropPiece(piece, this->bestPath.back());
        cout<<"\nThe board position after alphabeta turn is"<<endl;
        this->board.printBoard();
        gamePath++;
        win=checkWinBoard(board);
        if(win)
        {
           cout<<"\nAlphaBeta methodology won! \n GAME OVER"<<endl;
            break; //stop game
        }
        //***********Alphabeta Logic ends********************************
    }

    //print game statistics and end
      cout<<"\nTotal length of the game: "<< gamePath;
      cout<<"\nTotal number of nodes generated and expanded are: "<< (totalNodes +1 + nodesGenerated.size()) ;
      memorySize=(totalNodes+1)*nodeSize + nodesGenerated.size();
      cout<<"\nThe size of memory used by the program: "<< memorySize;
      cout <<"\nExecution time: "<< executionTime << endl;
}
