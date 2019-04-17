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
        bool hasSurroundingReds(int, int, int);

        /**
        * Returns count of adjacent reds
        */
        int getConnectedBlacks ();

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
		* clear board of all pieces
		*/
        void clearBoard();
        void printBoard ();

	private:
        const static int ROWS = 6;
        const static int COLS = 7;
        vector<vector<int>> board;
        vector<vector<int>> reds_list;
        vector<vector<int>> black_list;

};
#endif				//CONNECT4GAME_H guard
