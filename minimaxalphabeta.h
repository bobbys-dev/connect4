#ifndef MINMAXALPHABETA_H
#define MINMAXALPHABETA_H

#include <iostream>
#include <vector>
#include <queue>
#include "connect4game.h"

namespace AI{

class AlphaBeta {
    /**
    * Struct for hold path and desired value
    */
    struct some_struct {
        int value;
        vector<int> mpath;
        some_struct() {
            value = 0;
            mpath = {0};
        }

    };

public:
   vector<int> bestPath; // keeps track of best path

    /**
    * alphaBetaSearch returns an action corresponding to best possible move
    * This function computes minimax decision from current state,
    * and also uses bookkeeping alpha and beta parameters
    * Searches plausible moves down to cutoff depth. Values
    * are backed up through tree as recursion unwinds.
    * Must set depth to > 0;
    * Input: game state, player type (red = 1, black = -1), max depth to search
    * Returns structure containing both (min or max) value and path to that value
    **/
    some_struct alphaBetaSearch(Connect4Game, int /*player*/, int /*max depth*/);

   /**
   * clears internal game board
   **/
   void clearGameBoard();

   /**
   * prints internal game board
   **/
   void printGameBoard();

   /**
   * Plays game based on computer as max player
   */
   void humanVsComputerAlphaBeta(int, int);
private:
   Connect4Game gameState; //actual state of board

   /**
   * Check if search depth has been reached based on board state and depth.
   * It will ignore its position parameter and simply return TRUE if its
   * depth parameter exceeds a constant cutoff value.​
   * Input: board position, current depth of search
   * Output: true when depth has reached zero.
   * true for all terminal states eg when game is over. false otherwise
   **/
   bool cutoffTest(Connect4Game);

   /**
   * maxValue returns a utility value given game state, alpha, and beta
   * Input: game board state, player type, integers (lowerbound) and beta (upperbound)
   * (player type: red = 1, black = -1)
   * It uses one of the evaluation functions
   * contained in board game to determine utility value
   * Output: integer representing utility value
   **/
   int maxValue(Connect4Game, int /*player*/, int /*alpha*/, int /*beta*/);

   /**
   * minValue returns a utility value given game state, alpha, and beta
   * It uses one of the evaluation functions
   * contained in board game to determine utility value
   * Input: game board state, player type, integers alpha (lowerbound) and beta (upperbound)
   * (player type: red = 1, black = -1)
   * It uses one of the evaluation functions
   * Output: integer representing utility value
   **/
   int minValue(Connect4Game, int /*player*/, int /*alpha*/, int /*beta*/);

   /**
   * This function transition model that defines result of dropping a player's
   * piece into column. It returns the resultant state as if dropPiece()
   * were invoked.
   * Precondition: must be player's turn and move must be valid
   * Input: gameState, playerType, column
   * (playerType: Red = 1, Black = -1)
   * Postcondition: gameState of input it changed
   * Output: resultant state of game once player piece is dropped
   */
   Connect4Game result(Connect4Game, int /*player*/, int /*column*/);

   /**
   * Actions(s) returns vector set of possible columns to dropPiece
   * Input: gameState of Board
   * Output: vector of columns on which any piece may be dropped
   */
   vector<int> actions(Connect4Game);

};
} //end AI namespace
#endif //MINMAXALPHABETA_H guard
