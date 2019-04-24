#include "MiniMaxAB.h"
#include<bits/stdc++.h>
#include<vector>

using namespace std;


namespace AB {
MiniMaxAB::MiniMaxAB() {
    //initialize any internal member variables
}
vector<MiniMaxAB> bestPath;
bool MiniMaxAB::checkWinBoard(Connect4Game board)
{
    bool a;
    cout<<"Inside CheckWin"<<endl;
    a=this->board.checkWin(board);
    cout<<"Exiting CheckWin"<<endl;
    return a;
}



void MiniMaxAB::Eval(MiniMaxAB &session, int piece)
{
    int evaluationTable[6][7] = {{3, 4, 5, 7, 5, 4, 3},
                                 {4, 6, 8, 10,8, 6, 4},
                                 {5, 8, 11,13,11,8, 5},
                                 {5, 8, 11,13,11,8, 5},
                                 {4, 6, 8, 10,8, 6, 4},
                                 {3, 4, 5, 7, 5, 4, 3}};

        int utility = 0;
        int sum = 0;
        for (int i = 0; i < 6; i++)
            for (int j = 0; j <7; j++)
                if (session.board.getSlotValue(i,j) == 1)
                    sum += evaluationTable[i][j];
                else if (session.board.getSlotValue(i,j) == -1)
                    sum -= evaluationTable[i][j];
       // return utility + sum;
       cout<<"\nInside eval utility+sum= "<<utility+sum<<endl;
    session.value=utility+sum;

//    int score = 0;
//        for (int r= 0; r < 6; r++)
//            {
//                if (r <= 6-4)
//                {
//                    for (int c = 0; c < 7; c++)
//                    {
//                        score += getScore(session,r,c);
//                    }
//                }
//                else
//                {
//                    for (int c = 0; c <= 7-4; c++)
//                    {
//                        score += getScore(session,r,c);
//                    }
//                }
//            }
//
// session.value= score;
}

void MiniMaxAB::MoveGen(MiniMaxAB &session,int piece)
{
    cout<<"Inside Movegen"<<endl;
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
    cout<<"\nInside minimax search"<<endl;
    //bestPath.clear();
    unsigned int i;
    MiniMaxAB session;
    session.board=board;
    if(deepEnough(depth))
    {
        cout<<"\n Deep Enough"<<endl;
        Eval(session,piece);
        cout<<"\nAfter Eval"<<endl;
        cout<<"\n\nsession.value"<<session.value;
        if(piece==-1)
            session.value*=-1;
        return session;
    }

    session.MoveGen(session,piece);
    cout<<"\nThe child size is:"<<session.child.size()<<endl;
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
                bestPath.push_back(session.child[i]);
            }
        if(PT >= UT)
            {
                session.child[i].value=PT;
                return session.child[i];
            }
    }
    //session.board=board;
	session.value=PT;
	return session;
	cout<<"Exiting Minimax Search"<<endl;
}

void MiniMaxAB::humanVsComputerMinimaxAB(int depth,int peice)
{
    cout<<"Inside Human Vs Computer"<<endl;
    MiniMaxAB temp;
    int m;
    int columnNumber;
    bool win;

    for(m=0;m<22;m++)
    {
        int pass[6][7];
        peice=1;
        bestPath.clear();
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
				pass[i][j] = bestPath[bestPath.size() -1].board.getSlotValue(i,j);
			}
		}
		setBoard1(pass);
        cout<<"\nThe board position after computer's turn"<<endl;
        this->board.printBoard();
        win=checkWinBoard(board);
        if(win)
        {
            cout<<"Game Over"<<endl;
            break;
        }
        peice=-1;
        cout<<"\nYour turn, enter the column number you want to drop the coin:\n";
        cin>>columnNumber;
        this->board.dropPiece(peice,columnNumber);
        this->board.printBoard();
        checkWinBoard(board);
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
    this->board.getSlotValue(x,y);
}

void MiniMaxAB::setBoard1(int a[6][7] )
{
    this->board.setBoard(a);
}

} //end namespace AB
