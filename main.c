

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
int move[2] = {0,0};
vector2i* waysToWin[] ={{fillVec(0,0)},{fillVec(0,1)},{fillVec(0,2)},{fillVec(1,0)},{fillVec(1,1)},{fillVec(1,2)},
	{fillVec(2,0)},{fillVec(2,1)},{fillVec(2,2)},{fillVec(0,0)},{fillVec(1,0)},{fillVec(2,0)},{fillVec(0,1)},{fillVec(1,1)},{fillVec(2,1)},
	{fillVec(0,2)},{fillVec(1,2)},{fillVec(2,2)},{fillVec(0,0)},{fillVec(1,1)},{fillVec(2,2)},{fillVec(0,2)},{fillVec(1,1)},{fillVec(2,0)}};

struct vector2i
{
	int x;
	int y;
};

struct vector2i fillVec(int q, int w)
{
	struct vector2i z;
	z.x=q;
	z.y=w;
	return z;
}
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

bool checkToWin()
{
	int row1[3] = {board[0][0], board[0][1], board[0][2]};
	int row2[3] = {board[1][0], board[1][1], board[1][2]};
	int row3[3] = {board[2][0], board[2][1], board[2][2]};

	int column1[3] = {board[0][0], board[1][0], board[2][0]};
	int column2[3] = {board[0][1], board[1][1], board[2][1]};
	int column3[3] = {board[0][2], board[1][2], board[2][2]};

	int diagonal1[3] = {board[0][0], board[1][1], board[2][2]};
	int diagonal2[3] = {board[0][2], board[1][1], board[2][0]};

	if(numMoves%2 == 0)
	{
		if(row1[0]+row1[1]+row1[2] == X+X)
		{
			if(row1[0] == empty)
			{
				move[0] = 0;
				move[1] = 0;
				return true;
			}
			else if(row1[1] == empty)
			{
				move[0] = 0;
				move[1] = 1;
				return true;
			}
			else
			{
				move[0] = 0;
				move[1] = 2;
				return true;
			}
		}
		else if(row2[0]+row2[1]+row2[2] == X+X)
		{
			if(row2[0] == empty)
			{
				move[0] = 1;
				move[1] = 0;
				return true;
			}
			else if(row2[1] == empty)
			{
				move[0] = 1;
				move[1] = 1;
				return true;
			}
			else
			{
				move[0] = 1;
				move[1] = 2;
				return true;
			}
		}
		else if(row3[0]+row3[1]+row3[2] == X+X)
		{
			if(row3[0] == empty)
			{
				move[0] = 2;
				move[1] = 0;
				return true;
			}
			else if(row3[1] == empty)
			{
				move[0] = 2;
				move[1] = 1;
				return true;
			}
			else
			{
				move[0] = 2;
				move[1] = 2;
				return true;
			}
		}
		else if(column1[0]+column1[1]+column1[2] == X+X)
		{
			if(column1[0] == empty)
			{
				move[0] = 0;
				move[1] = 0;
				return true;
			}
			else if(column1[1] == empty)
			{
				move[0] = 1;
				move[1] = 0;
				return true;
			}
			else
			{
				move[0] = 2;
				move[1] = 0;
			}
		}
		else if(column2[0]+column2[1]+column2[2] == X+X)
		{
			if(column2[0] == empty)
			{
				move[0] = 0;
				move[1] = 1;
				return true;
			}
			else if(column2[1] == empty)
			{
				move[0] = 1;
				move[1] = 1;
				return true;
			}
			else
			{
				move[0] = 2;
				move[1] = 1;
				return true;
			}
		}
		else if(column3[0]+column3[1]+column3[2] == X+X)
		{
			if(column3[0] == empty)
			{
				move[0] = 0;
				move[1] = 2;
				return true;
			}
			else if(column3[1] == empty)
			{
				move[0] = 1;
				move[1] = 2;
				return true;
			}
			else
			{
				move[0] = 2;
				move[1] = 2;
				return true;
			}
		}
		else if(diagonal1[0]+diagonal1[1]+diagonal1[2] == X+X)
		{
			if(diagonal[0] == empty)
			{
				move[0] = 0;
				move[1] = 0;
				return true;
			}
			else if(diagonal1[1] == empty)
			{
				move[0] = 1;
				move[1] = 1;
				return true;
			}
			else
			{
				move[0] = 2;
				move[1] = 2;
				return true;
			}
		}
		else if(diagonal2[0]+diagonal2[1]+diagonal2[2] == X+X)
		{
			if(diagonal2[0] == empty)
			{
				move[0] = 0;
				move[1] = 2;
				return true;
			}
			else if(diagonal2[1] == empty)
			{
				move[0] = 1;
				move[1] = 1;
				return true;
			}
			else
			{
				move[0] = 2;
				move[1] = 0;
				return true;
			}
		}
	}
	else
	{
		if(row1[0]+row1[1]+row1[2] == O+O)
		{
			if(row1[0] == empty)
			{
				move[0] = 0;
				move[1] = 0;
				return true;
			}
			else if(row1[1] == empty)
			{
				move[0] = 0;
				move[1] = 1;
				return true;
			}
			else
			{
				move[0] = 0;
				move[1] = 2;
				return true;
			}
		}
		else if(row2[0]+row2[1]+row2[2] == O+O)
		{
			if(row2[0] == empty)
			{
				move[0] = 1;
				move[1] = 0;
				return true;
			}
			else if(row2[1] == empty)
			{
				move[0] = 1;
				move[1] = 1;
				return true;
			}
			else
			{
				move[0] = 1;
				move[1] = 2;
				return true;
			}
		}
		else if(row3[0]+row3[1]+row3[2] == O+O)
		{
			if(row3[0] == empty)
			{
				move[0] = 2;
				move[1] = 0;
				return true;
			}
			else if(row3[1] == empty)
			{
				move[0] = 2;
				move[1] = 1;
				return true;
			}
			else
			{
				move[0] = 2;
				move[1] = 2;
				return true;
			}
		}
		else if(column1[0]+column1[1]+column1[2] == O+O)
		{
			if(column1[0] == empty)
			{
				move[0] = 0;
				move[1] = 0;
				return true;
			}
			else if(column1[1] == empty)
			{
				move[0] = 1;
				move[1] = 0;
				return true;
			}
			else
			{
				move[0] = 2;
				move[1] = 0;
				return true;
			}
		}
		else if(column2[0]+column2[1]+column2[2] == O+O)
		{
			if(column2[0] == empty)
			{
				move[0] = 0;
				move[1] = 1;
				return true;
			}
			else if(column2[1] == empty)
			{
				move[0] = 1;
				move[1] = 1;
				return true;
			}
			else
			{
				move[0] = 2;
				move[1] = 1;
				return true;
			}
		}
		else if(column3[0]+column3[1]+column3[2] == O+O)
		{
			if(column3[0] == empty)
			{
				move[0] = 0;
				move[1] = 2;
				return true;
			}
			else if(column3[1] == empty)
			{
				move[0] = 1;
				move[1] = 2;
				return true;
			}
			else
			{
				move[0] = 2;
				move[1] = 2;
				return true;
			}
		}
		else if(diagonal1[0]+diagonal1[1]+diagonal1[2] == O+O)
		{
			if(diagonal[0] == empty)
			{
				move[0] = 0;
				move[1] = 0;
				return true;
			}
			else if(diagonal1[1] == empty)
			{
				move[0] = 1;
				move[1] = 1;
				return true;
			}
			else
			{
				move[0] = 2;
				move[1] = 2;
				return true;
			}
		}
		else if(diagonal2[0]+diagonal2[1]+diagonal2[2] == O+O)
		{
			if(diagonal2[0] == empty)
			{
				move[0] = 0;
				move[1] = 2;
				return true;
			}
			else if(diagonal2[1] == empty)
			{
				move[0] = 1;
				move[1] = 1;
				return true;
			}
			else
			{
				move[0] = 2;
				move[1] = 0;
				return true;
			}
		}
	}

	return false;
}

bool checkToBlockWin()
{
	int row1[3] = {board[0][0], board[0][1], board[0][2]};
	int row2[3] = {board[1][0], board[1][1], board[1][2]};
	int row3[3] = {board[2][0], board[2][1], board[2][2]};

	int column1[3] = {board[0][0], board[1][0], board[2][0]};
	int column2[3] = {board[0][1], board[1][1], board[2][1]};
	int column3[3] = {board[0][2], board[1][2], board[2][2]};

	int diagonal1[3] = {board[0][0], board[1][1], board[2][2]};
	int diagonal2[3] = {board[0][2], board[1][1], board[2][0]};

	if(numMoves%2 == 1)
	{
		if(row1[0]+row1[1]+row1[2] == X+X)
		{
			if(row1[0] == empty)
			{
				move[0] = 0;
				move[1] = 0;
				return true;
			}
			else if(row1[1] == empty)
			{
				move[0] = 0;
				move[1] = 1;
				return true;
			}
			else
			{
				move[0] = 0;
				move[1] = 2;
				return true;
			}
		}
		else if(row2[0]+row2[1]+row2[2] == X+X)
		{
			if(row2[0] == empty)
			{
				move[0] = 1;
				move[1] = 0;
				return true;
			}
			else if(row2[1] == empty)
			{
				move[0] = 1;
				move[1] = 1;
				return true;
			}
			else
			{
				move[0] = 1;
				move[1] = 2;
				return true;
			}
		}
		else if(row3[0]+row3[1]+row3[2] == X+X)
		{
			if(row3[0] == empty)
			{
				move[0] = 2;
				move[1] = 0;
				return true;
			}
			else if(row3[1] == empty)
			{
				move[0] = 2;
				move[1] = 1;
				return true;
			}
			else
			{
				move[0] = 2;
				move[1] = 2;
				return true;
			}
		}
		else if(column1[0]+column1[1]+column1[2] == X+X)
		{
			if(column1[0] == empty)
			{
				move[0] = 0;
				move[1] = 0;
				return true;
			}
			else if(column1[1] == empty)
			{
				move[0] = 1;
				move[1] = 0;
				return true;
			}
			else
			{
				move[0] = 2;
				move[1] = 0;
			}
		}
		else if(column2[0]+column2[1]+column2[2] == X+X)
		{
			if(column2[0] == empty)
			{
				move[0] = 0;
				move[1] = 1;
				return true;
			}
			else if(column2[1] == empty)
			{
				move[0] = 1;
				move[1] = 1;
				return true;
			}
			else
			{
				move[0] = 2;
				move[1] = 1;
				return true;
			}
		}
		else if(column3[0]+column3[1]+column3[2] == X+X)
		{
			if(column3[0] == empty)
			{
				move[0] = 0;
				move[1] = 2;
				return true;
			}
			else if(column3[1] == empty)
			{
				move[0] = 1;
				move[1] = 2;
				return true;
			}
			else
			{
				move[0] = 2;
				move[1] = 2;
				return true;
			}
		}
		else if(diagonal1[0]+diagonal1[1]+diagonal1[2] == X+X)
		{
			if(diagonal[0] == empty)
			{
				move[0] = 0;
				move[1] = 0;
				return true;
			}
			else if(diagonal1[1] == empty)
			{
				move[0] = 1;
				move[1] = 1;
				return true;
			}
			else
			{
				move[0] = 2;
				move[1] = 2;
				return true;
			}
		}
		else if(diagonal2[0]+diagonal2[1]+diagonal2[2] == X+X)
		{
			if(diagonal2[0] == empty)
			{
				move[0] = 0;
				move[1] = 2;
				return true;
			}
			else if(diagonal2[1] == empty)
			{
				move[0] = 1;
				move[1] = 1;
				return true;
			}
			else
			{
				move[0] = 2;
				move[1] = 0;
				return true;
			}
		}
	}
	else
	{
		if(row1[0]+row1[1]+row1[2] == O+O)
		{
			if(row1[0] == empty)
			{
				move[0] = 0;
				move[1] = 0;
				return true;
			}
			else if(row1[1] == empty)
			{
				move[0] = 0;
				move[1] = 1;
				return true;
			}
			else
			{
				move[0] = 0;
				move[1] = 2;
				return true;
			}
		}
		else if(row2[0]+row2[1]+row2[2] == O+O)
		{
			if(row2[0] == empty)
			{
				move[0] = 1;
				move[1] = 0;
				return true;
			}
			else if(row2[1] == empty)
			{
				move[0] = 1;
				move[1] = 1;
				return true;
			}
			else
			{
				move[0] = 1;
				move[1] = 2;
				return true;
			}
		}
		else if(row3[0]+row3[1]+row3[2] == O+O)
		{
			if(row3[0] == empty)
			{
				move[0] = 2;
				move[1] = 0;
				return true;
			}
			else if(row3[1] == empty)
			{
				move[0] = 2;
				move[1] = 1;
				return true;
			}
			else
			{
				move[0] = 2;
				move[1] = 2;
				return true;
			}
		}
		else if(column1[0]+column1[1]+column1[2] == O+O)
		{
			if(column1[0] == empty)
			{
				move[0] = 0;
				move[1] = 0;
				return true;
			}
			else if(column1[1] == empty)
			{
				move[0] = 1;
				move[1] = 0;
				return true;
			}
			else
			{
				move[0] = 2;
				move[1] = 0;
				return true;
			}
		}
		else if(column2[0]+column2[1]+column2[2] == O+O)
		{
			if(column2[0] == empty)
			{
				move[0] = 0;
				move[1] = 1;
				return true;
			}
			else if(column2[1] == empty)
			{
				move[0] = 1;
				move[1] = 1;
				return true;
			}
			else
			{
				move[0] = 2;
				move[1] = 1;
				return true;
			}
		}
		else if(column3[0]+column3[1]+column3[2] == O+O)
		{
			if(column3[0] == empty)
			{
				move[0] = 0;
				move[1] = 2;
				return true;
			}
			else if(column3[1] == empty)
			{
				move[0] = 1;
				move[1] = 2;
				return true;
			}
			else
			{
				move[0] = 2;
				move[1] = 2;
				return true;
			}
		}
		else if(diagonal1[0]+diagonal1[1]+diagonal1[2] == O+O)
		{
			if(diagonal[0] == empty)
			{
				move[0] = 0;
				move[1] = 0;
				return true;
			}
			else if(diagonal1[1] == empty)
			{
				move[0] = 1;
				move[1] = 1;
				return true;
			}
			else
			{
				move[0] = 2;
				move[1] = 2;
				return true;
			}
		}
		else if(diagonal2[0]+diagonal2[1]+diagonal2[2] == O+O)
		{
			if(diagonal2[0] == empty)
			{
				move[0] = 0;
				move[1] = 2;
				return true;
			}
			else if(diagonal2[1] == empty)
			{
				move[0] = 1;
				move[1] = 1;
				return true;
			}
			else
			{
				move[0] = 2;
				move[1] = 0;
				return true;
			}
		}
	}

	return false;
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

void chooseMove()
{
	if(checkToWin())
	{
		if(numMoves%2 == 0)
		{
			addPiece(X,move[0],move[1]);
		}
		else
		{
			addPiece(O,move[0],move[1]);
		}
	}
	else if(checkToBlockWin())
	{
		if(numMoves%2 == 0)
		{
			addPiece(X,move[0],move[1]);
		}
		else
		{
			addPiece(O,move[0],move[1]);
		}
	}
	else
	{
		for(int i = 0; i<8; i++)
		{
			int x = board[wayToWin[3i].x][waysToWin[3i].y];
			int y = board[wayToWin[3i+1].x][waysToWin[3i+1].y];
			int z = board[wayToWin[3i+2].x][waysToWin[3i+2].y];
			if(x+y+z == 1 || x+y+z == 4)
			{

			}
		}
		/
		//Actual move algorithm code
	}
}

/**
* Adds a piece to the board if the space is empty and the piece is empty.
*
*
*/
bool addPiece(int piece, int positionY, int positionX)
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
			board[positionY][positionX] = piece;
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

	if(numMoves%2==0)
	{
		addPiece(X,myMove[0],myMove[1]); //Player 2 places O
	}
	else
	{
		addPiece(O,0,0); //Player 1 places X
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
