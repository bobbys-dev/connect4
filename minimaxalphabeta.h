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
        std::vector<int> mpath;
        some_struct() {
            value = 0;
            mpath = {0};
        }

    };

public:

    /**
    * Recursively searches plausible moves down to cutoff depth. THe minimax values
    * are backed up through tree as recursion unwinds
    * Input: board state
    * Returns structure containing both (min or max) value and path to that value
    **/
    some_struct alphaBetaSearch(Connect4Game);

private:
   Connect4Game board; //actual state of board

   /**
   * Check if search depth has been reached based on board state and depth.
   * It will ignore its position parameter and simply return TRUE if its
   * depth parameter exceeds a constant cutoff value.​
   * Input: board position, current depth of search
   * Output: true for all depth greater than some fixed depth d.
   * true for all terminal states eg when game is over. false otherwise
   **/
   bool cutoffTest(Connect4Game, int);

   /**
   * maxValue returns a utility value given game state and alpha beta
   * Input: game board state, integers alpha and beta.
   * It uses one of the evaluation functions
   * contained in board game to determine utility value
   * Output: integer representing utility value
   **/
   int maxValue(Connect4Game);

   /**
   * minValue returns a utility value given game state and alpha beta
   * It uses one of the evaluation functions
   * contained in board game to determine utility value
   * Input: game board state, integers alpha and beta
   * Output: integer representing utility value
   **/
   int minValue(Connect4Game);



};
} //end AI namespace
#endif //MINMAXALPHABETA_H guard
