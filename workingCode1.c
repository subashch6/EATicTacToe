

/**
* Global Variables
*/
bool xWin;
bool oWin;
int numMoves = 0;
int X = 1;
int O = 4;
int empty = 0;
int board[3][3] = {{empty, empty, empty}, {empty, empty, empty}, {empty, empty, empty}};

/**
* This function checks to see if a particular array has a winning combo.
*
*
*/
bool hasWon(int* array)
{
	int sum = array[0] + array[1] + array[2];
	if(sum == 3)
	{
		xWin = true;
		return true;
	}
	else if(sum == 12)
	{
		oWin = true;
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
	if(board[positionX][positionY] == empty)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/**
* Calculates move to take
*	move[0] = xPosition
* move[1] = yPosition
*/

int* chooseMove()
{
	int move[2] = {0,0};

	//Code to fill move

	return move;
}

/**
* Adds a piece to the board if the space is empty and the piece is empty.
*
*
*/
bool addPiece(int piece, int positionX, int positionY)
{
	if(!isSpaceEmpty(positionX, positionY))
	{
		return false;
	}
	else
	{
		if(piece != X && piece != O)
		{
			return false;
		}
		else
		{
			board[positionX][positionY] = piece;
			numMoves += 1;
			return true;
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
	for (int i = 0; i < 3; i += 1)
	{
		char buffer[sizeof(int)*3 + sizeof(char)*2];
		sprintf(buffer,"%d %d %d",board[i][0],board[i][1],board[i][2]);
		displayString(i*3+4,buffer);
	}
}

task main()
{
	//displayBoard();

	/*	do
	{*/
	int* myMove = chooseMove();
	char buffer[sizeof(int)*2 + sizeof(char)];
	sprintf(buffer,"%d %d",*myMove,*(myMove+1));
	displayString(10,buffer);

	if(numMoves%2)
	{
		addPiece(O,myMove[0],myMove[1]); //Player 2 places O
	}
	else
	{
		addPiece(X,0,0); //Player 1 places X
	}
	checkBoardForWin();
	while(true)
	{
		displayBoard();
	}
	/*	}
	while(!oWin && !xWin && numMoves < 8);

	if(oWin == true)
	{
	//printf("Player two wins!");
	}
	else if(xWin == true)
	{
	//printf("Player one wins!");
	}
	else
	{
	//printf("It's a draw!");
	}*/
}
