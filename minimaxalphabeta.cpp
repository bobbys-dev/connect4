#include <climits>
#include "minimaxalphabeta.h"
#include <iostream>
#include <cstdlib>
using namespace std;

namespace AI {

   AlphaBeta::some_struct AlphaBeta::alphaBetaSearch(
      Connect4Game gameState, int playerType, int maxDepth) {

      cout<<"In alphaBetaSearch " << endl;
      some_struct best;
      best.value = maxValue(gameState, playerType, INT_MIN, INT_MAX);
      cout << "bestPath is ";
      for(int i = 0; i < bestPath.size(); i++) {
        cout << bestPath.at(i) << ", ";
      }
      cout << endl;
      //return action in _ACTIONS(gameState) with value v
     return best;
  }

   bool AlphaBeta::cutoffTest(Connect4Game gameState){
       cout << "In cutoffTest.." << endl;

      if (gameState.getDepthPlayed() <= 0) {
        cout << " cutoffTest: depth is zero.." << endl;
        return true;
      }
//      if(gameState.checkWin(gameState)) {
//        cout << "cutoffTest: There was a winner" << endl;
//         return true;
//      }
      cout << " not deep enough. Exiting cutoffTest" << endl<< endl;
      return false;
   }

   int AlphaBeta::maxValue(
      Connect4Game gameState, int playerType, int alpha, int beta){
        cout << "In maxValue. Depth is " << gameState.getDepthPlayed() << endl;

        vector<int> playableCols = actions(gameState);
        cout << " playableCols generated: ";
        for (int i = 0; i < playableCols.size(); i++) {
            cout << playableCols.at(i) << " ";
        }
        cout<< endl;

        // check if deep enough
        if ( cutoffTest(gameState) ) {
            int maxEval = INT_MIN;
            int bestCol;
            int tempEval;
            //get max of playableCols
            for (int i = 0; i < playableCols.size(); i++) {
                tempEval = gameState.evalBAlphaBeta(playerType,playableCols.at(i));
                if (maxEval < tempEval) {
                    maxEval = tempEval;
                    bestCol = playableCols.at(i);
                }
            }
            cout << " Exiting maxValue@cutoff test. max eval value and its bestCol are " << maxEval << " " << bestCol << endl;
            bestPath.push_back(bestCol); //save best col
            return maxEval; //return max eval
        }

      int v = INT_MIN; // -inf
      cout << endl;

      // must decrement current depth before next set of recursive calls
      gameState.setDepthPlayed(gameState.getDepthPlayed() - 1 );
      //switch player over for calcuations
      //for each possible column, get the highest of min's choices
      bestPath.push_back(0); //create dummy slot for next best path
       cout << "+In maxValue. Going into loop for each hypothetical action... " << endl;
      for (int i = 0; i < playableCols.size(); i++) {
         cout << " in maxValue. Doing hypothetical drop and checking max of results of min's possible plays" << endl;
         int m = minValue(result(gameState, playerType, playableCols.at(i)), -1*playerType, alpha, beta); //intermediate calculation
         cout << " in maxValue. Call to minValue resulted in m="<<m<< " for dropping into "<< playableCols.at(i) << endl;

         // choose max of v or m
         // if m is higher, that means playableCols(i) is the max of min so far
         if (v < m) {
            cout << "  1-maxValue. v < m where v is " << v << " and m is "<< m <<" and current highest playableCols(i) is " << playableCols.at(i) << endl;
            v = m;
            bestPath.back() = playableCols.at(i);
         }

         //beta is a cutoff value
         if (v >= beta) {
            cout << "  2-maxValue v is " << v << endl;
            cout << "  2-maxValue beta is " << beta << endl;
            cout << "  2-maxValue. No need to explore further, returning v=" << v << endl;
            return v;
         }
         alpha = (alpha<v) ? v : alpha; //alpha is max of v or itself
         cout << "  3-maxValue alpha is now " << alpha << endl;
      }

      cout << "   !-maxValue returning v=" << v << endl;
      return v;
   }

   int AlphaBeta::minValue(
      Connect4Game gameState, int playerType, int alpha, int beta) {
        cout << "In minValue. Depth is " << gameState.getDepthPlayed() << endl;

        vector<int> playableCols = actions(gameState);
        cout << " playableCols generated: ";
        for (int i = 0; i < playableCols.size(); i++) {
            cout << playableCols.at(i) << " ";
        }
        cout<< endl;
        // check if deep enough
        if ( cutoffTest(gameState) ) {
            int minEval = INT_MAX;
            int bestCol;
            int tempEval;
            //get max of playableCols
            for (int i = 0; i < playableCols.size(); i++) {
                tempEval = gameState.evalBAlphaBeta(playerType,playableCols.at(i));
                if (minEval > tempEval) {
                    minEval = tempEval;
                    bestCol = playableCols.at(i);
                }
            }
            cout << " Exiting minValue@cutoff test. min eval value and its bestCol are " << minEval << " " << bestCol << endl;
            bestPath.push_back(bestCol); //save best col
            return minEval; //return max eval
        }
      int v = INT_MAX; //+inf

      // must decrement current depth before next set of recursive calls
      gameState.setDepthPlayed( gameState.getDepthPlayed() - 1);
      //for each possible column, get the min of max's values
      playerType *= -1;
      bestPath.push_back(0); //create dummy slot for next best path
      for (int i = 0; i < playableCols.size(); i++) {
         int m = maxValue(result(gameState, playerType, playableCols.at(i)), -1*playerType, alpha, beta); //intermediate calculation
         cout << " in minValue. Call to maxValue resulted in m="<<m<< endl;

          // choose min of v or m
         if (m < v){
            cout << "  v is " << v << endl;
            v = m;
            cout << "  2-minminValue.  m < v where m is "<< m <<" and playableCols(i) is " << playableCols.at(i) << endl;
            bestPath.back() = playableCols.at(i);
         }

         if (v <= alpha) {
            cout << "  2-minValue v is " << v << endl;
            cout << "  2-minValue alpha is " << alpha << endl;
            cout << "  2-minValue. No need to explore further, returning v=" << v << endl;
           return v;
         }

         beta = !(beta<v)?v:beta; //beta is min of v or itself
         cout << "  3-minValue beta is now " << beta << endl;

      }

      cout << "   !-minValue returning v=" << v << endl;
      return v;
   }

   /**
   * result(s,a) is transition model that defines result of doing action a
   * in a state s. It returns a successor state.
   * Eg Result(In(Arad),Go(Zerind)) = In(Zerind)
   */
   Connect4Game AlphaBeta::result(
      Connect4Game gameState, int playerType, int col) {
          cout << "In result()... hypothethical drop into col " << col << endl;
         gameState.dropPiece(playerType, col);
         gameState.printBoard();
         return gameState;
   }

   /**
   * Actions(s) returns vector set of legal moves in a state s.
   * Eg Actions(In(Arad)) = {Go(Sibiu),Go(Timisora),Go(Zerind)}
   */
   vector<int> AlphaBeta::actions(Connect4Game gameState) {
      vector<int> playableCols;
      playableCols = gameState.getOpenColumns();
      return playableCols;
   }

  /**
   * clears internal game board
   **/
   void AlphaBeta::clearGameBoard() {
    this->gameState.clearBoard();
   }

   /**
   * prints internal game board
   **/
   void AlphaBeta::printGameBoard() {
       this->gameState.printBoard();

   }

  /**
   * Plays the game based on computer working as max player
   */
   void AlphaBeta::humanVsComputerAlphaBeta(int maxDepth, int playerType){
        some_struct s;
        srand(0);
        cout << "Playing Human VS CPU with search depth=" << maxDepth << endl;
        this->gameState.setDepthPlayed(maxDepth);
        cout << "Computer is " << playerType << endl << endl;
        int humanChoice;
        int maxRounds = 21;
        for (int i = 1; i <= maxRounds; i++) {
                cout<< "********************** ROUND " << i << endl;
            s = alphaBetaSearch(this->gameState, playerType, maxDepth);
            cout << "Search value returned " << s.value << endl;
            cout << "**********************Computer will play  " << bestPath.back() << endl;
            this->gameState.dropPiece(playerType, bestPath.back());
            printGameBoard();
            if (this->gameState.checkWin(this->gameState)) {
                cout << "computer won";
                return;
            }
            playerType *= -1;
            cout << "**********************Human making move" << endl;
            //this->gameState.dropPiece(playerType,i%7+1);
            this->gameState.makeRandomMove(playerType);
            //cin >>humanChoice; this->gameState.dropPiece(playerType,humanChoice);
            printGameBoard();
            if (this->gameState.checkWin(this->gameState)) {
                cout << "human won";
                return;
            }
            playerType *= -1;

        }
   }
} // end namespace AI
