#ifndef MINIMAXAB_H
#define MINIMAXAB_H

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <list>
#include "connect4game.h"

namespace AB {

struct structure
{
    int value;
    int path;
};


class MiniMaxAB{
    public:
        int col;
        Connect4Game board;
         vector<MiniMaxAB> child;
        MiniMaxAB();
         /** Function for Human vs Computer using MinmaxAB */
        void humanVsComputerMinimaxAB(Connect4Game,int,int);


        /** Function for MinimaxAB algorithm*/
        Connect4Game miniMaxSearch(Connect4Game,int,int,int,int);

        /**
        * Check if max depth is reached
        * Input: (input parameters)
        * Output: (what the function is returning)
        * Precondition: Game is still in progress with no winner
        * Postcondition: This function does not change any state
        */
        bool deepEnough(int);

        /**Function to check if a player has won*/
        int checkWin();

        /**Function which evaluates the board position and returns the number*/
        structure Eval(Connect4Game,int);
        void printGameBoard();
        void clearGameBoard();
        void MoveGen(Connect4Game,int);

};
} //end namespace AB
#endif // end MINIMAXAB_H guard
