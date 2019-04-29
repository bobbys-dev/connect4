#ifndef MINIMAXAB_H
#define MINIMAXAB_H

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <list>
#include "connect4game.h"

namespace AI {

class MiniMaxAB{
    public:
        Connect4Game board;
        vector<MiniMaxAB> child;
        vector<MiniMaxAB> bestPathMinmaxAB;
        int totalNodes=0,expandedNodes=0,col=0,value,dep;;
        MiniMaxAB();
         /** Function for Human vs Computer using MinmaxAB */
        void humanVsComputerMinimaxAB(int,int);

        /** Function for MinimaxAB algorithm*/
        MiniMaxAB miniMaxSearch(Connect4Game&,int,int,int,int,int=1);

        /**Check if max depth is reached*/
        bool deepEnough(int);

        /**Function which evaluates the board position and returns the number*/
        void Eval(MiniMaxAB &,int,int);

        /**Function which give score to the board based on the row and column number*/
        int getScore(MiniMaxAB &,int, int);

        /**Function which prints game board*/
        void printGameBoard();

        /**Function which clears the game board*/
        void clearGameBoard();

        /**Move generator Function*/
        void MoveGen(MiniMaxAB &,int);

        /**Function which returns the peice value at the specified board position*/
        int getSlotValueBoard(int,int);

        /**Function which sets the board position to new board position*/
        void setBoard1(int [6][7] );

        /**Function which checks if there are any connected four in the board*/
        bool checkWinBoard(Connect4Game);

        /**Function which checks if the move specified by the user is a valid move*/
        bool checkValidMoveBoard(Connect4Game,int );

};
} //end namespace AI
#endif // end MINIMAXAB_H guard
