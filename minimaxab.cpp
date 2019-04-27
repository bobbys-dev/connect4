#include "MiniMaxAB.h"
#include<bits/stdc++.h>
#include<vector>

using namespace std;


namespace AI {
MiniMaxAB::MiniMaxAB() {
    //initialize any internal member variables
}
//vector<MiniMaxAB> bestPath;
bool MiniMaxAB::checkWinBoard(Connect4Game board)
{
    bool a;
    a=this->board.checkWin(board);
    return a;
}

bool MiniMaxAB::checkValidMoveBoard(Connect4Game board,int column)
{
    bool b;
    b=this->board.checkValidMove(board,column);
    return b;
}

void MiniMaxAB::Eval(MiniMaxAB &session, int piece)
{
    session.value=this->board.evalA(session.board,piece);
}

void MiniMaxAB::MoveGen(MiniMaxAB &session,int piece)
{
    int i,j=0;
    MiniMaxAB session1;
    session1.board=session.board;
    if(j==0)
    {
        for(i=0;i<6;i++)
            {
                if(session1.board.getSlotValue(i,j)==0 && session1.board.getSlotValue(i,j)!=-1 && session1.board.getSlotValue(i,j)!=1)
                {
                    session1.board.dropPiece(piece,j);
                    session1.col=j;
                    child.push_back(session1);
                    break;
                }
            }
    }
    session1.board=session.board;
    j++;
    if(j==1)
    {
        for(i=0;i<6;i++)
            {
                if(session1.board.getSlotValue(i,j)==0 && session1.board.getSlotValue(i,j)!=-1 && session1.board.getSlotValue(i,j)!=1 && j==1)
                {
                    session1.board.dropPiece(piece,j);
                    session1.col=j;
                    child.push_back(session1);
                    break;
                }
            }

    }
    j++;
    session1.board=session.board;
    if(j==2)
    {
        for(i=0;i<6;i++)
            {
                if(session1.board.getSlotValue(i,j)==0 && session1.board.getSlotValue(i,j)!=-1 && session1.board.getSlotValue(i,j)!=1)
                {
                    session1.board.dropPiece(piece,j);
                    session1.col=j;
                    child.push_back(session1);
                    break;
                }
            }

    }
    j++;
    session1.board=session.board;
    if(j==3)
    {
      for(i=0;i<6;i++)
            {
                if(session1.board.getSlotValue(i,j)==0 && session1.board.getSlotValue(i,j)!=-1 && session1.board.getSlotValue(i,j)!=1)
                {
                    session1.board.dropPiece(piece,j);
                    session1.col=j;
                    child.push_back(session1);
                    break;
                }
            }
    }
    j++;
    session1.board=session.board;
    if(j==4)
    {
        for(i=0;i<6;i++)
            {
                if(session1.board.getSlotValue(i,j)==0 && session1.board.getSlotValue(i,j)!=-1 && session1.board.getSlotValue(i,j)!=1)
                {
                    session1.board.dropPiece(piece,j);
                    session1.col=j;
                    child.push_back(session1);
                    break;
                }
            }

    }
    j++;
    session1.board=session.board;
    if(j==5)
    {
        for(i=0;i<6;i++)
            {
                if(session1.board.getSlotValue(i,j)==0 && session1.board.getSlotValue(i,j)!=-1 && session1.board.getSlotValue(i,j)!=1)
                {
                    session1.board.dropPiece(piece,j);
                    session1.col=j;
                    child.push_back(session1);
                    break;
                }
            }

    }
    j++;

    session1.board=session.board;
    if(j==6)
    {
        for(i=0;i<6;i++)
            {
                if(session1.board.getSlotValue(i,j)==0 && session1.board.getSlotValue(i,j)!=-1 && session1.board.getSlotValue(i,j)!=1)
                {
                    session1.board.dropPiece(piece,j);
                    session1.col=j;
                    child.push_back(session1);
                    break;
                }
            }
    }
}


MiniMaxAB MiniMaxAB::miniMaxSearch(Connect4Game& board,int depth, int piece,int UT,int PT)
{
    unsigned int i;
    MiniMaxAB session;
    session.board=board;
    if(deepEnough(depth))
    {
        Eval(session,piece);
        if(piece==-1)
            session.value*=-1;
        return session;
    }

    session.MoveGen(session,piece);
    //cout<<"\nThe child size is:"<<session.child.size()<<endl;
    if(session.child.size()==0)
    {
        Eval(session,piece);
        if(piece==-1)
            session.value*=-1;
        return session;
    }
    for(i=0;i<session.child.size();i++)
    {
        MiniMaxAB Successor= miniMaxSearch(session.child[i].board,depth+1,(-1*piece),(-1*PT),(-1*UT));
        int newValue=-1*Successor.value;
        if(newValue > PT)
            {
                PT = newValue;
                if(depth == 0)
                bestPathMinmaxAB.push_back(session.child[i]);
            }
        if(PT >= UT)
            {
                session.child[i].value=PT;
                return session.child[i];
            }
    }
	session.value=PT;
	return session;

}

void MiniMaxAB::humanVsComputerMinimaxAB(int depth,int peice)
{
    MiniMaxAB temp;
    int m;
    int columnNumber;
    bool win;

    for(m=0;m<22;m++)
    {
        int pass[6][7];
        peice=1;
        win=false;
        bestPathMinmaxAB.clear();
        temp = miniMaxSearch(board,depth,peice,100,-120);
//        cout<<"\ntemp.value"<<temp.value;
//        cout<<"\n\nAfter executing Minimax Search in humanVsComputer"<<endl;
//        cout<<"temp.col"<<temp.col<<endl;
//        this->board.dropPiece(peice,temp.col);
        for(int i=0;i<6;i++)
		{
			for(int j=0;j<7;j++)
			{
				//find child with move 0 and then store it into board
				pass[i][j] = bestPathMinmaxAB[bestPathMinmaxAB.size() -1].board.getSlotValue(i,j);
			}
		}
		setBoard1(pass);
        cout<<"\nThe board position after computer's turn is"<<endl;
        this->board.printBoard();
        win=checkWinBoard(board);
        if(win)
        {
            cout<<"AI(MinmaxAB) won the game!! Better luck next time"<<endl;
            break;
        }
        peice=-1;
        win=false;
        cout<<"\nYour turn, Enter the column number you want to drop the coin:\n"<<endl;
        cin>>columnNumber;
        bool valid=checkValidMoveBoard(board,columnNumber);
        if(!valid)
        {
            cout<<"\nInvalid column number,Enter the valid column number again:\n";
            cin>>columnNumber;
        }
        this->board.dropPiece(peice,columnNumber);
         cout<<"\nThe board position after your(Human) turn is"<<endl;
        this->board.printBoard();
        win=checkWinBoard(board);
        if(win)
        {
            cout<<"Congratulations!!! You won the game"<<endl;
            break;
        }
    }
cout<<"\n\nThank You";
}

bool MiniMaxAB::deepEnough(int d)
{
    return d >= 2;
}

void MiniMaxAB::printGameBoard()
{
   this->board.printBoard();
}
void MiniMaxAB::clearGameBoard()
{
    this->board.clearBoard();
}

int MiniMaxAB::getSlotValueBoard(int x,int y)
{
    return this->board.getSlotValue(x,y);
}

void MiniMaxAB::setBoard1(int a[6][7] )
{
    this->board.setBoard(a);
}

} //end namespace AB
