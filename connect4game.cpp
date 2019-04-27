#include "connect4game.h"
#include <cmath>
using namespace std;

namespace AI {

/**
* Constructor creates a board game, which is a n x m grid
* starting with empty values
*/
Connect4Game::Connect4Game() {
  // initialize any necessary members
  vector<vector<int>> bd(this->ROWS, vector<int>(this->COLS, 0));
  this->board = bd;
  this->current_depth = 0;
}

/**
* Returns count of adjacent reds
*/
int Connect4Game::getConnectedReds(){
  int count = 0;
  for (int r = 0; r < board.size (); r++) {
        for (int c = 0; c < board[0].size (); c++){
            //hardcoded red = 1
            if (board.at(r).at(c) == 1 && hasSurroundingPieces(1,r,c)){
                count += 1;
	        }
        }
    }
  return count;
}

/**
* Returns count of adjacent blacks
*/
int Connect4Game::getConnectedBlacks() {
   int count = 0;
   for (int r = 0; r < board.size (); r++) {
         for (int c = 0; c < board[0].size (); c++){
             //hardcoded black = -1
             if (board.at(r).at(c) == -1 && hasSurroundingPieces(-1,r,c)){
                 count += 1;
 	        }
         }
     }
   return count;
}

/**
* Returns true if adjacent to any red
*/
bool Connect4Game::hasSurroundingPieces(int playerType, int row, int col){
    //Check straight up down
    if(col >=0 && col < this->COLS) {
      if(row >= 0 && row < this->ROWS - 1) {
          //check row above
          if (board.at(row+1).at(col) == playerType) {
              return true;
          }
      }

      if(row > 0 && row < this->ROWS) {
          //check row below
          if (board.at(row-1).at(col) == playerType) {
              return true;
          }
      }
    }

    //Check straight left right
    if (row >= 0 && row < this->ROWS){
        if(col >= 0 && col < this->COLS - 1) {
          //check col to right
          if (board.at(row).at(col+1) == playerType) {
              return true;
          }
        }

        if(col > 0 && col < this->COLS) {
          //check col to left
          if (board.at(row).at(col-1) == playerType) {
              return true;
          }
        }
    }

    //Check diagonal upper & lower right
    if(col >=0 && col < this->COLS-1) {
      if(row >= 0 && row < this->ROWS - 1) {
          //check upper right
          if (board.at(row+1).at(col+1) == playerType) {
              return true;
          }
      }

      if(row > 0 && row < this->ROWS) {
          //check lower right
          if (board.at(row-1).at(col+1) == playerType) {
              return true;
          }
      }
    }


    //Check diagonal upper and lower left
    if(col >0 && col < this->COLS) {
      if(row >= 0 && row < this->ROWS - 1) {
          //check upper right
          if (board.at(row+1).at(col-1) == playerType) {
              return true;
          }
      }

      if(row > 0 && row < this->ROWS) {
          //check lower right
          if (board.at(row-1).at(col-1) == playerType) {
              return true;
          }
      }
    }
  return false;
}

/**
* Returns count of all reds and black in board
*/
int Connect4Game::getTotalPieces() {
    int count = 0;
    for (int r = 0; r > board.size (); r++) {
        for (int c = 0; c < board[0].size (); c++){
            if (board.at (r).at (c) != 0) {
              count += 1;
            }
        }
    }
  return count;
}

/**
* Mutator function that drops a piece onto the board of a specified column
*/
int Connect4Game::dropPiece (int piece, int col) {
//  cout << "In dropPiece()..." << endl;

    int row = 0;
    if ((piece == -1 || piece == 1) && col >= 0 && col < this->COLS) {
        // 1) find lowest empty slot in the column
        while (row < this->ROWS && board.at(row).at(col) != 0) {
            row += 1;
        }

        // 2) insert piece into slot if it's empty
        if (row < this->ROWS && board.at(row).at(col) == 0) {
            board.at(row).at(col) = piece;
        }
    }
}

void Connect4Game::removeTopPiece(int col) {
//  cout << "In removeTopPiece()..." << endl;

    int row = 0;
    if (col >= 0 && col < this->COLS) {
        // 1) find lowest empty slot in the column
        while (row < this->ROWS && board.at(row).at(col) != 0) {
            row += 1;
        }
        // 2) empty the slot
        row -= 1;
        if (row >= 0 && row < this->ROWS && board.at(row).at(col) != 0) {
            board.at(row).at(col) = 0;
        }
    }
}


/**
* Drop a player piece in random column
*/
void Connect4Game::makeRandomMove(int player) {


    if (player == 1 || player == -1) {
        int col = rand()% this->COLS;
        if (player == 1) {
            cout << "Randomly dropping R into col index " << col <<"\n";
        } else {
            cout << "Randomly dropping B into col index " << col <<"\n";
        }
       this->dropPiece(player, col);
    }

}

/**
* Increment depth of board.
*/

void Connect4Game::setDepthPlayed(int new_depth) {
   this->current_depth = new_depth;
}

/**
* Get current depth of board. This number is used to
* decide if game state has been played to a far enough depth
*/
int Connect4Game::getDepthPlayed() {
   return this->current_depth;
}


/**
* Get all open columns by checking if at topmost row
* is empty
*/
vector<int> Connect4Game::getOpenColumns(){
   vector<int> playableCols;
   int row = this->ROWS-1; //topmost row
   for (int col = 0; col < this->COLS; col++) {
      if (board.at(row).at(col) == 0) {
         playableCols.push_back(col);
      }
   }
   return playableCols;
}

    /**
    * Return the value at given row and col
    */
    int Connect4Game::getSlotValue(int row, int col) {
      return this->board.at(row).at(col);
    }

  bool Connect4Game::checkWin(Connect4Game board)
  {
 //     cout<<"Inside connect4 checkwin"<<endl;
      int WIN=4;
      bool win;
    {
    for (int c = 0; c < 7; c++)
    for (int r = 0; r < 6; r++)
   if (getSlotValue(r,c) == 1)
   {
      // Check row
      int count = 0;
      for (int d = 0; d < WIN; d++)
         if ((r+d < ROWS) &&
            (getSlotValue(r+d,c) == 1)) count++;
      if (count == WIN) return true;

      // Check column
      count = 0;
      for (int d = 0; d < WIN; d++)
         if ((c+d < COLS) &&
            (getSlotValue(r,c+d) == 1)) count++;
      if (count == WIN) return true;

      // Check first diagonal
      count = 0;
      for (int d = 0; d < WIN; d++)
         if ((r+d < ROWS) && (c+d < COLS) &&
            (getSlotValue(r+d,c+d) == 1)) count++;
      if (count == WIN) return true;

      // Check second diagonal
      count = 0;
      for (int d = 0; d < WIN; d++)
         if ((r-d >= 0) && (c+d < COLS) &&
            (getSlotValue(r-d,c+d) == 1)) count++;
      if (count == WIN) return true;
   }
   return false;
  }
  {
    for (int c = 0; c < 7; c++)
    for (int r = 0; r < 6; r++)
   if (getSlotValue(r,c) == -1)
   {
      // Check row
      int count = 0;
      for (int d = 0; d < WIN; d++)
         if ((r+d < ROWS) &&
            (getSlotValue(r+d,c) == -1)) count++;
      if (count == WIN) return true;

      // Check column
      count = 0;
      for (int d = 0; d < WIN; d++)
         if ((c+d < COLS) &&
            (getSlotValue(r,c+d) == -1)) count++;
      if (count == WIN) return true;

      // Check first diagonal
      count = 0;
      for (int d = 0; d < WIN; d++)
         if ((r+d < ROWS) && (c+d < COLS) &&
            (getSlotValue(r+d,c+d) == -1)) count++;
      if (count == WIN) return true;

      // Check second diagonal
      count = 0;
      for (int d = 0; d < WIN; d++)
         if ((r-d >= 0) && (c+d < COLS) &&
            (getSlotValue(r-d,c+d) == -1)) count++;
      if (count == WIN) return true;
   }
   return false;
  }
  }


/**
* Clear pieces from board
*/
void Connect4Game::clearBoard() {
    vector<vector<int>> bd(this->ROWS, vector<int>(this->COLS, 0));
    this->board = bd;
    this->current_depth = 0;
}

/**
* Prints board game
*/
void Connect4Game::printBoard () {
    cout << "r\\c ";
    for (int c = 0; c < board[0].size (); c++) {
        cout << c << "  ";
    }

    cout << endl;
    for (int r = board.size () - 1; r >= 0; r--) {
        cout << r << "   ";

        for (int c = 0; c < board[0].size (); c++) {
            switch (board.at(r).at(c))
              {
              case -1:
        	cout << "B  ";
        	break;
              case 0:
        	cout << "_  ";
        	break;
              case 1:
        	cout << "R  ";
        	break;
              default:
        	break;
          }
    }
    cout << '\n';
  }
}

/**
* Evaluation A function for present state of board
*/
int Connect4Game::evalA() {
   //To be implmented by NP
}

/**
* Evaluation B function for present state of board
* Returns 'goodness' of playing a column
*/
int Connect4Game::evalB(int playerType, int col) {
    playerType = 1;
    cout << "In evalB, computing util for col " << col << endl;


    //test if connect4
    cout << " testing for connect 4" << col << endl;

    this->dropPiece(playerType,col);
    if(this->checkWin(*this)){
        return 1000; //highest weight
    }
    this->removeTopPiece(col);

   //column 3 is the best col to start with
   int middleCol = (this->COLS - 1) / 2;

   //get first nonempty row at column
   int row = 0;
   while (this->board.at(row).at(col) != 0 && row < this->ROWS) {
      row++;
   }

   //check if inserting piece at row will make a connection
    // score 1 for any surrounding pieces
   int surroundingPieces = 0;

    // upper right
    if(row < this->ROWS - 1 && col < this->COLS - 1) {
        if(this->getSlotValue(row+1,col+1) == playerType){
            surroundingPieces++;
        }
    }

    // upper left
    if(row < this->ROWS - 1 && col > 0) {
        if(this->getSlotValue(row+1,col-1) == playerType){
            surroundingPieces++;
        }
    }

    // right
    if(row < this->ROWS && col < this->COLS - 1) {
        if(this->getSlotValue(row,col+1) == playerType){
            surroundingPieces++;
        }
    }

    // left
    if(row < this->ROWS && col > 0) {
        if(this->getSlotValue(row,col-1) == playerType){
            surroundingPieces++;
        }
    }

    // lower right
    if(row > 0 && col < this->COLS - 1) {
        if(this->getSlotValue(row-1,col+1) == playerType){
            surroundingPieces++;
        }
    }

    // lower left
    if(row > 0 && col > 0) {
        if(this->getSlotValue(row-1,col-1) == playerType){
            surroundingPieces++;
        }
    }

    cout << "  util... for possible piece="<< playerType<< " to drop in row, col " << row << ", "<< col << endl;
    cout << "   util... (middleCol - abs(middleCol - col)) is " << (middleCol - abs(middleCol - col)) << endl;
    cout << "   util... surroundingPieces is " << surroundingPieces << endl;

   // add utility of intermediate values
   int util =  (middleCol - abs(middleCol - col))*3 + surroundingPieces;
   cout << "evalB is returning util of " << util << endl << endl;
   return util;
}

}// end namespace AI
