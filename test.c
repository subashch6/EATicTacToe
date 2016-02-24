
/**
* The enum sets X and O to particular values to allow the AI to determine whether or not the game has been won.
*
*/
enum Pieces
{
	X = 1,
	O = 4,
	empty = 0
};

// the actual board
int board[3][3] = {{empty, empty, empty}, {empty, empty, empty}, {empty, empty, empty}};

/**
* This function checks to see if a particular array has a winning combo.
*
*
*/
bool hasWon(int* array)
{
	int sum = array[0] + array[1] + array[2];
	if(sum == 3 || sum == 12)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/**
* This checks all of the different ways the game could be won and put them all
* into the hasWon function to see if there are any winning combos.
*
*
*/
bool checkBoardForWin()
{
	int row1[3] = {board[0][0], board[0][1], board[0][2]};
	int row2[3] = {board[1][0], board[1][1], board[1][2]};
	int row3[3] = {board[2][0], board[2][1], board[2][2]};

	int column1[3] = {board[0][0], board[1][0], board[2][0]};
	int column2[3] = {board[0][1], board[1][1], board[2][1]};
	int column3[3] = {board[0][2], board[1][2], board[2][2]};

	int diagonal1[3] = {board[0][0], board[1][1], board[2][2]};
	int diagonal2[3] = {board[0][2], board[1][1], board[2][0]};

	return (hasWon(row1) || hasWon(row2) || hasWon(row3) || hasWon(column1) || hasWon(column2) || hasWon(column3) || hasWon(diagonal1) || hasWon(diagonal2));
}

/**
* Checks to see if the target is empty or not.
*
*
*/
bool isSpaceEmpty(int positionX, int positionY)
{
	if(board[positionX][positionY] == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/**
* Adds a piece to the board if the space is empty and the piece is empty.
*
*
*/
void addPiece(int piece, int positionX, int positionY)
{
	if(!isSpaceEmpty(positionX, positionY))
	{
		return;
	}
	else
	{
		if(piece != 1 && piece != 4)
		{
			return;
		}
		else
		{
			board[positionX][positionY] = piece;
		}
	}
}

/**
*
* Just a simple displayer.
*
*/
void displayBoard()
{
	for (int i = 0; i < 3; i = i + 1)
  {
    for (int j = 0; j < 3; j = j + 1)
    {
      nxtDisplayTextLine(3 * i + j, "Value at %d", 3 * i + j, " = %d", board[i][j]);
    }
  }
}

task main()
{
	displayBoard();

	addPiece(X, 0, 0);
	addPiece(O, 0, 1);

	displayBoard();
}
