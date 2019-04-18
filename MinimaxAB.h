#ifndef MINIMAXAB_H
#define MINIMAXAB_H

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include "connect4game.h"

namespace AB {
class MiniMaxAB {
    public:

        MiniMaxAB();
         /** Function for Human vs Computer using MinmaxAB */
        void humanVsComputerMinimaxAB(MiniMaxAB,int,int);


        /** Function for MinimaxAB algorithm*/
        int miniMaxSearch(MiniMaxAB,int,int,int,int);

        /**
        * Check if max depth is reached
        * Input: (input parameters)
        * Output: (what the function is returning)
        * Precondition: Game is still in progress with no winner
        * Postcondition: This function does not change any state
        */
        bool deepEnough(int);

        /**Function to check if a player has won*/
        void checkWin();

        /**Function which evaluates the board position and returns the number*/
        int Eval();

        void printGameBoard();
        void clearGameBoard();

    private:
        Connect4Game board;


};
} //end namespace AB
#endif // end MINIMAXAB_H guard
