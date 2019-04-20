#include "MiniMaxAB.h"
#include<bits/stdc++.h>
#include<vector>

using namespace std;


namespace AB {
MiniMaxAB::MiniMaxAB() {
    //initialize any internal member variables
}

int MiniMaxAB::checkWin()
{
//    {
//    for(int i = 0; i<6; i++)
//    {
//        for(int j = 0; j<7; j++)
//        {
//        if(tab[j][i]==1 && tab[j+1][i+1]==1 && tab[j+2][i+2]==1 && tab[j+3][i+3]==1)
//            {
//            end = true;
//            std::cout << "\nPLAYER 1 WIN!" << std::endl;
//            }
//        if(tab[j][i]==1 && tab[j+1][i-1]==1 && tab[j+2][i-2]==1 && tab[j+3][i-3]==1)
//            {
//            std::cout << "\nPLAYER 1 WIN!" << std::endl;
//            end = true;
//            }
//        if(tab[j][i]==2 && tab[j+1][i-1]==2 && tab[j+2][i-2]==2 && tab[j+3][i-3]==2)
//            {
//            std::cout << "\nPLAYER 2 WIN!" << std::endl;
//            end=true;
//            }
//        else if(tab[j][i]==2 && tab[j-1][i-1]==2 && tab[j-2][i-2]==2 && tab[j-3][i-3]==2)
//            {
//            end = true;
//            std::cout << "\nPLAYER 2 WIN!" << std::endl;
//            }
//        else if(tab[j][i]==1 && tab[j][i-1]==1 && tab[j][i-2]==1 && tab[j][i-3]==1)
//            {
//            std::cout << "\nPLAYER 1 WIN!" << std::endl;
//            end = true;
//            }
//        else if(tab[j][i]==1 && tab[j-1][i]==1 && tab[j-2][i]==1 && tab[j-3][i]==1)
//            {
//            std::cout << "\nPLAYER 1 WIN!" << std::endl;
//            end = true;
//            }
//        else if(tab[j][i]==2 && tab[j][i-1]==2 && tab[j][i-2]==2 && tab[j][i-3]==2)
//            {
//            std::cout << "\nPLAYER 2 WIN!" << std::endl;
//            end = true;
//            }
//        else if(tab[j][i]==2 && tab[j-1][i]==2 && tab[j-2][i]==2 && tab[j-3][i]==2)
//            {
//            std::cout << "\nPLAYER 2 WIN!" << std::endl;
//            end = true;
//            }
//        }
//    }
return 0;
}


structure MiniMaxAB::Eval(Connect4Game board, int piece)
{
    structure s;
    s.path=0;
    s.value=0;
    return s;
}

void MiniMaxAB::MoveGen(Connect4Game board,int piece)
{
    int i,j=0;
    MiniMaxAB child1;
    child1.board=board;
    for(j=0;j<7;j++)
    {
        for(i=0;i<6;i++)
        {
            if(board[i][j]==0)
            {
                child1.board.dropPiece(piece,i);
                child.push_back(child1);
                break;
            }
        }
    }
}


 Connect4Game::miniMaxSearch(Connect4Game board,int depth, int piece,int UT,int PT)
{
    int value,i;
    MiniMaxAB resultSucc;
    if(deepEnough(depth))
    {
        structure s;
        s= Eval(board,piece);
        value=s.value;
        board.col= s.path;
        return board;
    }
    else
    {
        MoveGen(board,piece);
        for(i=0;i<child.size();i++)
        {
          resultSucc= miniMaxSearch(child[i].board,depth+1,-1*PT,-1*UT)
        }
    }


    return;
}
void MiniMaxAB::humanVsComputerMinimaxAB(Connect4Game board,int depth,int peice)
{
    int i=1;
    int columnNumber;
    while(i<=42)
    {
        MiniMaxAB temp;
        temp = miniMaxSearch(board,depth,peice,100,-120);
        this->board.dropPiece(peice,temp.col);
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

void MiniMaxAB::printGameBoard()
{
   this->board.printBoard();
}
void MiniMaxAB::clearGameBoard()
{
    this->board.clearBoard();
}

} //end namespace AB
