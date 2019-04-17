#include "MiniMaxAB.h"
#include<bits/stdc++.h>

using namespace std;
namespace AB {
MiniMaxAB::MiniMaxAB() {
    //initialize any internal member variables
}

int MiniMaxAB::miniMaxSearch(int depth, int piece,int A,int B)
{//Need to implement MinimaxAB algorithm
    if(deepEnough(depth))
    {
        return 1;//Code need to be changed
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
void MiniMaxAB::humanVsComputerMinimaxAB(int depth,int piece)
{
    int i=1;
    int columnNumber;
    while(i<=42)
    {
        columnNumber = miniMaxSearch(depth,piece,100,-120);
        this->board.dropPiece(columnNumber,piece);
        cout<<"\nThe board position after computer's turn"<<endl;
        this->board.printBoard();
        checkWin();
        cout<<"\nYour turn, enter the column number you want to drop the coin:\n";
        cin>>columnNumber;
        this->board.dropPiece(columnNumber,piece);
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

} //end namespace AB
