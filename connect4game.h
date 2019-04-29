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
       * Return vector of integers columns of which a piece may be dropped
       * in current game state.
       */
       vector<int> getOpenColumns();

       /**
      * Return the value at given row and col
      * Red = 1, black = -1
      */
      int getSlotValue(int /*row*/, int /*col*/);

       /**
       * Checks if connect 4 by any piece.
       * Return true if there is winning player
       */
       bool checkWin(Connect4Game /*unused*/);

		/**
		* clear board of all pieces
		*/
      void clearBoard();

      /**
      * printboard
      */
      void printBoard ();

      /**
      * Mutator function to set board member variable
      * Input: int array represeting new board
      * Postcondtion: this member's board is changed to match the input array
      */
      void setBoard(int[6][7]);

      /**
      * Function to check if column is valid for drop piece
      * Input: game state, col
      * Output: returns true if column is open
      */
      bool checkValidMove(Connect4Game,int /*column*/);

      /**
      * Scorees board
      * Input: game state, row, col
      * Output: returns weighted scoring on grid
      */
      int getScore(Connect4Game &,int , int);

      /**
 		* Evaluation A function for present state of board. Unused.
 		*/
 		int evalA(Connect4Game,int);

 		/**
 		* Evaluation B (Eval 2) function for present state of board
      * used by Alphabeta search
      * Input: playerType (1 = red, -1 = black), col is column to evaluate
      * Output: Returns a scoring based on connectedness and column weight
      * Returns highest score if there is a connect 4
 		*/
 		int evalBAlphaBeta(int /*playerType*/, int /*col*/);

      /**
 		* Evaluation B (Eval 2) function for present state of board used by minmaxab.
      * Input: game state to evaluate, player piece to play
      * Output: Returns a scoring based on centrally weighted grid
 		*/
 		int evalBMinmax(Connect4Game /*board*/,int /* piece*/);

 		/**
 		* Evaluation C (eval 1) function for present state of board
      * using minimasab search
      * Input: game state to evaluate, player piece to play
      * Output: Returns a scoring based on centrally weighted grid
 		*/
 		int evalCMinmax(Connect4Game,int);

      /**
  		* Evaluation C (eval 1) function for present state of board
       * using alphabeta search
       * Input: playerType (1 = red, -1 = black), col is column to evaluate
       * Output: Returns a scoring based on connectedness and column weight
       * Returns highest score if there is a connect 4
 	 	*/
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
