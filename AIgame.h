#ifndef AIGAME_H_INCLUDED
#define AIGAME_H_INCLUDED
#include "connect4game.h"
#include "MinimaxAB.h"
#include "minimaxalphabeta.h"


using namespace std;
namespace AI
{
    class AIgame: public MiniMaxAB, public AlphaBeta
    {
        public:
        void MinmaxVsAlphabeta(int,int);
    };
}
#endif // AIGAME_H_INCLUDED
