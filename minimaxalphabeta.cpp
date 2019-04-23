#include <climits>
#include "minimaxalphabeta.h"

using namespace std;

namespace AI {
   AlphaBeta::some_struct AlphaBeta::alphaBetaSearch(Connect4Game gameState) {
      some_struct best;

      best.value = maxValue(gameState, INT_MIN, INT_MAX);
      //return action in _ACTIONS(gameState) with value v
     return best;
  }

   bool AlphaBeta::cutoffTest(Connect4Game gameState, int depth){
      return true;
   }

   int AlphaBeta::maxValue(Connect4Game gameState, int alpha, int beta){
      if (cutoffTest(gameState)) {
         return gameState.evalB();
      }

      int v = INT_MIN; // -inf
      for (/**each a in Actions(gameState)**/) {
         int m = minValue( _Result(s,a), alpha, beta); //intermediate calculation
         v = (v<m)?m:v; // choose max of v or m
         if (v >= beta) {
            return v;
         }
         alpha = (alpha<v)?v:alpha; //alpha is max of v or itself
      }

      return v;
   }

   int AlphaBeta::minValue(Connect4Game gameState, int alpha, int beta) {
      if (cutoffTest(gameState)) {
         return gameState.evalB();
      }

      int v = INT_MAX; //+inf
      for (/**each a in Actions(gameState)**/) {
         int m = maxValue( _Result(s,a), alpha, beta); //intermediate calculation
         v = !(m<v)?v:m; // choose min of v or m
         if (v <= alpha) {
            return v;
         }
         beta = !(beta<v)?v:beta; //beta is min of v or itself
      }

      return v;
   }

} // end namespace AI
