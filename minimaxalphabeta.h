#define MINMAXALPHABETA_H
#include <iostream>
#include <vector>

class MinMaxAlphaBeta {
public:
    /**
    * Recursively searches plausible moves down to depth.
    * Input: board position, current depth of search, and player to move
    * red = 1, black = -1 So the initial call to compute the best move from the position CURRENT should be
    * Returns structure containing both (min or max) value and path to that value
    **/
    some_struct miniMaxAlphaBeta(int, int, int, int, int);​

private:

   /**
   * Check if search depth has been reached based on positino and depth.
   * It will ignore its position parameter and simply return TRUE if its
   * depth parameter exceeds a constant cutoff value.​
   * Input: board position, current depth of search, and player to move
   * red = 1, black = -1 So the initial call to compute the best move from the position CURRENT should be
   * Output: TRUE if search should be stopped at current level, else FALSE.
   **/
   bool deepEnough(int, int);


    struct some_struct {
        int value;​
        vector<int> path;
    };
};
