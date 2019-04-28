#include "AIgame.h"
#include "MiniMaxAB.h"
#include "minimaxalphabeta.h"
#include<iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;
using namespace AI;

static int gamePath=0;
static int executionTime=0;
static int nodes=0;
static int nodes2=0;

void AIgame::MinmaxVsAlphabeta(int depth,int piece)
{
    MiniMaxAB temp;
    int m;
    bool win;
    AlphaBeta alphabeta_session;
    alphabeta_session.evalType = 1; // tell alphabeta which eval to run
    some_struct alphabeta_search_result; //for alphabeta search results
    this->gameState.setDepthPlayed(8); //set search depth for alphabeta
    int memorySize1,memorySize2,nodeSize=43;

    for(m=0;m<22;m++)
    {
        //***********Minmax Logic begins*********************************
        MiniMaxAB temp;
        int m,columnNumber,pass[6][7];
        bool win=false;
        piece=1;
        bestPathMinmaxAB.clear();
        auto start = high_resolution_clock::now();
        temp = miniMaxSearch(board,depth,piece,100,-120);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        executionTime+=duration.count();
        nodes+=temp.totalNodes;
        for(int i=0;i<6;i++)
		{
			for(int j=0;j<7;j++)
			{
				//find child with move 0 and then store it into board
				pass[i][j] = bestPathMinmaxAB[bestPathMinmaxAB.size() -1].board.getSlotValue(i,j);
			}
		}
		setBoard1(pass);
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
        piece=-1;
        win=false;
        start = high_resolution_clock::now();
        alphabeta_search_result = alphaBetaSearch(this->board,piece,depth);
        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);
        executionTime+=duration.count();
        this->board.dropPiece(piece, this->bestPath.back());
        nodes2 += nodesGenerated.size();
        vector<int> ng;
        nodesGenerated = ng; // reset nodes generated
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
      cout<<"\nTotal number of nodes generated and expanded for MinimaxAB are: "<< (nodes +1)<<endl;
      cout<<"\nTotal number of nodes generated and expanded for AlphaBetaSearch are: "<< nodes2 << endl ;
      memorySize1=(nodes+1)*nodeSize;
      memorySize2= nodes2;
      cout<<"\nThe size of memory used by the MinimaxAB: "<< memorySize1;
      cout<<"\nThe size of memory used by the AlphaBetaSearch: "<< memorySize2;
      cout <<"\nExecution time: "<< executionTime << endl;
}
void AIgame::MinmaxVsMinmax(int depth,int piece)
{
    MiniMaxAB temp;
    int m;
    bool win;
    int memorySize1,memorySize2,nodeSize=43;
    for(m=0;m<22;m++)
    {
        //***********Minmax Logic begins*********************************
        MiniMaxAB temp1,temp2;
        int m,columnNumber,pass[6][7];
        bool win=false;
        piece=1;
        bestPathMinmaxAB.clear();
        auto start = high_resolution_clock::now();
        temp1 = miniMaxSearch(board,depth,piece,100,-120);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        executionTime+=duration.count();
        nodes+=temp1.totalNodes;
        for(int i=0;i<6;i++)
		{
			for(int j=0;j<7;j++)
			{
				//find child with move 0 and then store it into board
				pass[i][j] = bestPathMinmaxAB[bestPathMinmaxAB.size() -1].board.getSlotValue(i,j);
			}
		}
		setBoard1(pass);
        this->board.printBoard();
        gamePath++;
        win=checkWinBoard(board);
        if(win)
        {
           cout<<"\nMinmaxAB(Eval1) methodology won! \n GAME OVER"<<endl;
            break; //stop game
        }

        win=false;
        piece=-1;
        bestPathMinmaxAB.clear();
        start = high_resolution_clock::now();
        temp2 = miniMaxSearch(board,depth,piece,100,-120,2); //For Eval2 , we are sending 2 as the last parameter
        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);
        executionTime+=duration.count();
        nodes+=temp2.totalNodes;
        for(int i=0;i<6;i++)
		{
			for(int j=0;j<7;j++)
			{
				//find child with move 0 and then store it into board
				pass[i][j] = bestPathMinmaxAB[bestPathMinmaxAB.size() -1].board.getSlotValue(i,j);
			}
		}
		setBoard1(pass);
        this->board.printBoard();
        gamePath++;
        win=checkWinBoard(board);
        if(win)
        {
           cout<<"\nMinmaxAB(Eval2) methodology won! \n GAME OVER"<<endl;
            break; //stop game
        }
    }

    //print game statistics and end
      cout<<"\nTotal length of the game: "<< gamePath;
      cout<<"\nTotal number of nodes generated and expanded for MinimaxAB are: "<< (nodes +1)<<endl;
      memorySize1=(nodes+1)*nodeSize;
      cout<<"\nThe size of memory used by the MinimaxAB: "<< memorySize1;
      cout <<"\nExecution time: "<< executionTime << endl;
}
void AIgame::AlphaBetaVsAlphaBeta(int depth,int piece)
{

}
