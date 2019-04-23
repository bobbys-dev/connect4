/**
* Interfaces used to return the state of a board game
*/
#ifndef CONNECT4GAME_H
#define CONNECT4GAME_H

#include <vector>
#include <cstdlib> //random
#include <iostream> //cout

using namespace std;

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
		* clear board of all pieces
		*/
        void clearBoard();
        void printBoard ();

        /**
 		* Evaluation A function for present state of board
 		*/
 		int evalA();

 		/**
 		* Evaluation B function for present state of board
 		*/
 		int evalB(int, int);

	private:
        const static int ROWS = 6;
        const static int COLS = 7;
        vector<vector<int>> board;
        vector<vector<int>> reds_list;
        vector<vector<int>> black_list;
        int current_depth; // used to count current depth of board state

};
#endif				//CONNECT4GAME_H guard
