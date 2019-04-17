#define MINMAXALPHABETA_H
#include <iostream>
#include <vector>
#include <queue>

class MinMaxAlphaBeta {
public:
    /**
    * Recursively searches plausible moves down to depth.
    * Input: board position, current depth of search, and player to move
   *    max player = 1, min player = -1
    * Returns structure containing both (min or max) value and path to that value
    **/
    some_struct miniMaxAlphaBeta(int, int, int, int, int);​

private:

   /**
   * Check if search depth has been reached based on positino and depth.
   * It will ignore its position parameter and simply return TRUE if its
   * depth parameter exceeds a constant cutoff value.​
   * Input: board position, current depth of search
   * Output: TRUE if search should be stopped at current level, else FALSE.
   **/
   bool deepEnough(int, int);

    /**
   * Plausible-move generator, which returns queue list of nodes representing
   *  moves that can be made by Player in Position.
   * Input: board position,  and player to move
   *    max player = 1, min player = -1
   * Output: queue of nodes
   **/
    queue<int> moveGen(int, int );

    /**
    * Static evaluation function returns "goodness" based on input.
    * position: position of player
    *    max player = 1, min player = -1
    * returns: number representing goodness of position from standpoint of player
    */
    int staticEval1(int, int);

    /**
    * Struct for hold path and desired value
    */
    struct some_struct {
        int value;​
        vector<int> path;
    };
};
