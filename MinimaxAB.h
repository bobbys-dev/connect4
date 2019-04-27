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
        int col=0;
        int value,dep;
        Connect4Game board;
         vector<MiniMaxAB> child;
        MiniMaxAB();
         /** Function for Human vs Computer using MinmaxAB */
        void humanVsComputerMinimaxAB(int,int);


        /** Function for MinimaxAB algorithm*/
        MiniMaxAB miniMaxSearch(Connect4Game&,int,int,int,int);

        /**
        * Check if max depth is reached
        * Input: (input parameters)
        * Output: (what the function is returning)
        * Precondition: Game is still in progress with no winner
        * Postcondition: This function does not change any state
        */
        bool deepEnough(int);



        /**Function which evaluates the board position and returns the number*/
        void Eval(MiniMaxAB &,int);
        int getScore(MiniMaxAB &,int, int);
        void printGameBoard();
        void clearGameBoard();
        void MoveGen(MiniMaxAB &,int);
        int getSlotValueBoard(int,int);
        void setBoard1(int [6][7] );
        bool checkWinBoard(Connect4Game);
        bool checkValidMoveBoard(Connect4Game,int );

};
} //end namespace AI
#endif // end MINIMAXAB_H guard
