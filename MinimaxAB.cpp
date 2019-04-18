#include "MiniMaxAB.h"
#include<bits/stdc++.h>

using namespace std;
namespace AB {
MiniMaxAB::MiniMaxAB() {
    //initialize any internal member variables
}

int MiniMaxAB::Eval()
{
    return 2;
}

int MiniMaxAB::miniMaxSearch(MiniMaxAB board,int depth, int piece,int Alpha,int Beta)
{

    if(deepEnough(depth))
    {
        return 0;//Code need to be changed
    }
    int bestValue;
    if(piece==1)//Maximizing Player
    {
        bestValue=INT_MIN;




    }
    else//Minimising Player
    {
        bestValue=INT_MAX;

    }

    return 0;
}
void MiniMaxAB::humanVsComputerMinimaxAB(MiniMaxAB board,int depth,int peice)
{
    int i=1;
    int columnNumber;
    while(i<=42)
    {
        columnNumber = miniMaxSearch(board,depth,peice,100,-120);
        this->board.dropPiece(peice,columnNumber);
        cout<<"\nThe board position after computer's turn"<<endl;
        this->board.printBoard();
        checkWin();
        peice=-1;
        cout<<"\nYour turn, enter the column number you want to drop the coin:\n";
        cin>>columnNumber;
        this->board.dropPiece(peice,columnNumber);
        this->board.printBoard();
        checkWin();
        i++;
    }
}

bool MiniMaxAB::deepEnough(int d)
{
    return d >= 3;
}

void MiniMaxAB::checkWin()
{
 //add check win logic
}
void MiniMaxAB::printGameBoard()
{
   this->board.printBoard();
}
void MiniMaxAB::clearGameBoard()
{
    this->board.clearBoard();
}

} //end namespace AB
