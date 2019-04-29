#include "AIgame.h"
#include "MiniMaxAB.h"
#include "minimaxalphabeta.h"
#include<iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;
using namespace AI;

static int gamePath=0,executionTime=0,tnode=0,enodes=0;
static int gameNodesGen=0;
static int gameNodesExp=0;

void AIgame::MinmaxVsAlphabeta(int depth,int piece)
{
    MiniMaxAB temp;
    int m;
    bool win;
    this->evalType = 1; // tell alphabeta which eval to run
    some_struct alphabeta_search_result; //for alphabeta search results
    this->gameState.setDepthPlayed(depth); //set search depth for alphabeta
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
        tnode=temp.totalNodes;
        enodes=temp.expandedNodes;
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
        this->gameState.board = this->board.board; //transfer board to alpabeta
        start = high_resolution_clock::now();
        alphabeta_search_result = alphaBetaSearch(this->gameState,piece,depth);
        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);
        executionTime+=duration.count();
        this->board.dropPiece(piece, this->bestPath.back());
        gameNodesGen += nodesGenerated.size();
        gameNodesExp += nodesExpanded.size();
        nodesGenerated.clear(); // reset nodes generated
        nodesExpanded.clear();
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
      cout<<"\nGame's max depth was set to: "<< depth;
      cout<<"\nTotal length of the game: "<< gamePath;
      cout<<"\nTotal number of nodes generated in MinimaxAB are: "<< (tnode +1)<<endl;
      cout<<"\nTotal number of nodes expanded in MinimaxAB are: "<< (enodes +1)<<endl;
      cout<<"\nTotal number of nodes generated in AlphaBetaSearch are: "<< gameNodesGen << endl ;
      cout<<"\nTotal number of nodes expanded in AlphaBetaSearch are: "<< gameNodesExp << endl ;
      memorySize1=(enodes+1)*nodeSize;
      memorySize2= gameNodesExp;
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
        tnode=temp1.totalNodes;
        enodes=temp1.expandedNodes;
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
        tnode=temp2.totalNodes;
        enodes=temp2.expandedNodes;
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
      cout<<"\nTotal number of nodes generated in MinimaxAB are: "<< (tnode +1)<<endl;
      cout<<"\nTotal number of nodes expanded in MinmaxAB(Eval1) are: "<< (enodes +1)<<endl;
      memorySize1=(enodes)*nodeSize;
      cout<<"\nThe size of memory used by the MinimaxAB: "<< memorySize1;
      cout <<"\nExecution time: "<< executionTime << endl;
}

void AIgame::AlphaBetaVsAlphaBeta(int maxDepth,int piece)
{

   int gameNodesGen1 = 0;
   int gameNodesGen2 = 0;
   int gameNodesExp1 = 0;
   int gameNodesExp2 = 0;
   some_struct alphabeta_search_result; //for alphabeta search results
   this->board.setDepthPlayed(maxDepth); //set search depth for alphabeta
   this->evalType = -1; // tell alphabeta which eval to run

   for(int m=1;m<=21;m++)
   {
      cout << "Round " << m << endl;
      //***********Player 1 logic begins*********************************
      this->evalType *= -1; // tell alphabeta which eval to run
      piece=1;
      auto start = high_resolution_clock::now();
      alphabeta_search_result = alphaBetaSearch(this->board,piece,maxDepth);
      auto stop = high_resolution_clock::now();
      auto duration = duration_cast<microseconds>(stop - start);
      executionTime += duration.count();
      this->board.dropPiece(piece, this->bestPath.back());
      gameNodesGen1 += nodesGenerated.size();
      gameNodesExp1 += nodesExpanded.size();
      vector<int> ng;
      nodesGenerated = ng; // reset nodes generated
      nodesExpanded = ng;
      this->board.printBoard();
      gamePath++;
      if(checkWinBoard(board))
      {
         cout<<"\nEvaluation function 1 won! \n GAME OVER"<<endl;
         break; //stop game
      }

      //***********Player 1 Logic ends***********************************

      //***********Alphabeta Logic begins******************************
      this->evalType *= -1; // tell alphabeta which eval to run
      piece=-1;
      start = high_resolution_clock::now();
      alphabeta_search_result = alphaBetaSearch(this->board,piece,maxDepth);
      stop = high_resolution_clock::now();
      duration = duration_cast<microseconds>(stop - start);
      executionTime += duration.count();
      this->board.dropPiece(piece, this->bestPath.back());
      gameNodesGen2 += nodesGenerated.size();
      gameNodesExp2 += nodesExpanded.size();
      nodesGenerated.clear(); // reset nodes generated
      nodesExpanded.clear();
      this->board.printBoard();
      gamePath++;
      if(checkWinBoard(board))
      {
         cout<<"\nEvaluation function 2 won! \n GAME OVER"<<endl;
         break; //stop game
      }
      //***********Alphabeta Logic ends********************************
   }

   //print game statistics and end
   cout<<"\nGame's max depth was set to: "<< maxDepth;
   cout<<"\nTotal length of the game: "<< gamePath;
     cout<<"\nTotal number of nodes generated for Eval 1: "<< gameNodesGen1 <<endl;
     cout<<"\nTotal number of nodes generated for Eval 2: "<< gameNodesGen2 << endl;
     cout<<"\nTotal number of nodes expanded for Eval 1: "<< gameNodesExp1 <<endl;
     cout<<"\nTotal number of nodes expanded for Eval 2: "<< gameNodesExp2 << endl;
     int memorySize1= gameNodesExp1;
     int memorySize2= gameNodesExp2;
     cout<<"\nThe size of memory used by Eval 1: "<< memorySize1;
     cout<<"\nThe size of memory used by Eval 2: "<< memorySize2;
     cout <<"\nExecution time: "<< executionTime << endl;


}
