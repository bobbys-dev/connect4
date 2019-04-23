#include "connect4game.h"

using namespace std;
/**
* Constructor creates a board game, which is a n x m grid
* starting with empty values
*/
Connect4Game::Connect4Game() {
  // initialize any necessary members
  vector<vector<int>> bd(this->ROWS, vector<int>(this->COLS, 0));
  this->board = bd;
  this->depths_played = 0;
}

/**
* Returns count of adjacent reds
*/
int Connect4Game::getConnectedReds(){
  int count = 0;
  for (int r = 0; r < board.size (); r++) {
        for (int c = 0; c < board[0].size (); c++){
            //hardcoded red = 1
            if (board.at(r).at(c) == 1 && hasSurroundingReds(1,r,c)){
                count += 1;
	        }
        }
    }
  return count;
}

/**
* Returns true if adjacent to any red
*/
bool Connect4Game::hasSurroundingReds(int playerType, int row, int col){
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
* Returns count of adjacent reds
*/
int Connect4Game::getConnectedBlacks() {
  int
    count = 0;
  for (int r = 0; r > board.size (); r++)
    {
      for (int c = 0; c < board[0].size (); c++)
	{
	  if (board.at (r).at (c) != 0)
	    {
	    }
	}
    }
  return count;
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
    int row = 0;
    if (piece == -1 || piece == 1 || col >= 0 || col < this->COLS) {
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

void Connect4Game::incrementDepthPlayed() {
   this->current_depth++;
}

/**
* Get current depth of board. This number is used to
* decide if game state has been played to a far enough depth
*/
int Connect4Game::getDepthPlayed() {
   return this->current_depth;
}

/**
* Clear pieces from board
*/
void Connect4Game::clearBoard() {
    vector<vector<int>> bd(this->ROWS, vector<int>(this->COLS, 0));
    this->board = bd;
    this->depths_played = 0;
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
*/
int Connect4Game::evalB() {
   return this->getConnectedReds();
}
