/**
* Interfaces used to return the state of a board game
*/
#ifndef CONNECT4GAME_H
#define CONNECT4GAME_H

#include <vector>
#include <cstdlib> //random
#include <iostream> //cout

using namespace std;
namespace AI {
class Connect4Game {
    public:
        /**
        * Constructor creates a board game, which is a n x m grid
        * starting with empty values
        */
        Connect4Game ();

        /**
        * Returns count of adjacent reds
        */
        int getConnectedReds ();

        /**
        * Returns count of adjacent reds
        */
        int getConnectedBlacks ();

        /**
        * checks if board at (row,col) has any pieces that match
        * supplied playerType parameter
        * Input: playerType, row, and col
        * plyaterType must = 1 for red, or = -1 for black
        * Returns: True if there is any match, else false
        **/
        bool hasSurroundingPieces(int, int, int);

        /**
        * Returns count of all reds and black in board
        */
        int getTotalPieces ();

        /**
        * Mutator function that drops a piece onto the board of a specified column
        * piece: 1 = red, -1 = black
        * col: column in which to drop the piece
        * Invariant: must be a valid piece and column
        */
        int dropPiece (int, int);

        /**
        * Mutator function that removes top piece from column
        * Input: int column
        * Post condition: piece from column is removed
        */
        void removeTopPiece (int);

		/**
		* Drop a player piece in random column
		* Input: integer where 1 = red player, -1 = black player
		* Pre: board must have a slot for player's piece to occupy
		* Post condition: another player piece is added on board
		*/
        void makeRandomMove (int);

        /**
       * Increment depth of board.
       * Postcondition: current_depth is incremented by 1.
       */
       void setDepthPlayed(int);

       /**
       * Get current depth of board. This number is used to
       * decide if  game state has been played to a far enough depth
       * E.g. if we've played enough turns
       * Return: current number of turns played
       */
       int getDepthPlayed();

       /**
       * Return vector of columns of which a piece may be dropped
       * in current state.
       */
       vector<int> getOpenColumns();

       /**
      * Return the value at given row and col
      */
      int getSlotValue(int /*row*/, int /*col*/);

       /**
       * Return true if there is winning player
       */
       bool checkWin(Connect4Game /*unused*/);

		/**
		* clear board of all pieces
		*/
        void clearBoard();
        void printBoard ();
        void setBoard(int[6][7] );
        bool checkValidMove(Connect4Game,int);
        int getScore(Connect4Game &,int , int);

        /**
 		* Evaluation A function for present state of board
 		*/
 		int evalA(Connect4Game,int);

 		/**
 		* Evaluation B function for present state of board
 		*/
 		int evalBAlphaBeta(int, int);
 		int evalBMinmax(Connect4Game,int);
 		/**
 		* Evaluation C function for present state of board
 		*/
 		int evalCMinmax(Connect4Game,int);
 		int evalCAlphaBeta(int,int);
        int curCol;
	//private:
        const static int ROWS = 6;
        const static int COLS = 7;
        vector<vector<int>> board;
        int current_depth; // used to count current depth of board state


};
}// end namespace AI
#endif				//CONNECT4GAME_H guard
