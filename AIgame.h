#ifndef AIGAME_H_INCLUDED
#define AIGAME_H_INCLUDED
#include "connect4game.h"
#include "MinimaxAB.h"
#include "minimaxalphabeta.h"


using namespace std;
namespace AI
{
   /**
   * Driver class that extends with minimax and alphabeta Searches
   * Each method runs different cpu scenarios
   */
    class AIgame: public MiniMaxAB, public AlphaBeta
    {
        public:
        void MinmaxVsAlphabeta(int,int);
        void MinmaxVsMinmax(int,int);
        void AlphaBetaVsAlphaBeta(int ,int );
    };
}
#endif // AIGAME_H_INCLUDED
