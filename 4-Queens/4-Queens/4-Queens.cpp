#include <iostream>
using namespace std;


int findQueenRowPosition(int board[4][4])
{
	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 4; i++)
		{
			if (board[j][i] == 2)
			{
				return i;
			}
		}
	}
}

int findQueenColPosition(int board[4][4])
{
	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 4; i++)
		{
			if (board[j][i] == 2)
			{
				return j;
			}
		}
	}
}

void occupieTopRightCorner(int board[4][4],int row,int col)
{
	int i = row, j = col;
	while (j != 0 or i != 4)
	{
		if ((j > 3 or i > 3) or (j < 0 or i < 0))
		{
			break;
		}
		if (board[j][i] != 2)
		{
			board[j][i] = 1;
		}
		board[j][i] = 1;
		i++;
		j--;
	}
}

void occupieTopLeftCorner(int board[4][4], int row, int col)
{
	int i = row, j = col;
	while (j >= 0 or i >= 0)
	{
		if ((j > 3 or i > 3) or (j < 0 or i < 0))
		{
			break;
		}
		if (board[j][i] != 2)
		{
			board[j][i] = 1;
		}
		board[j][i] = 1;
		i--;
		j--;
	}
}

void occupieBottomRightCorner(int board[4][4], int row, int col)
{
	int i = row, j = col;
	while (i != 3 or j != 3)
	{
		if ((j > 3 or i > 3) or (j < 0 or i < 0))
		{
			break;
		}
		if (board[j][i] != 2)
		{
			board[j][i] = 1;
		}
		board[j][i] = 1;
		i++;
		j++;
	}
}

void occupieBottomLeftCorner(int board[4][4], int row, int col)
{
	int i = row, j = col;
	while (i != 4 or j!=0)
	{
		if ((j > 3 or i > 3) or (j < 0 or i < 0))
		{
			break;
		}
		if (board[j][i] != 2)
		{
			board[j][i] = 1;
		}
		i--;
		j++;
	}
}

int occupiePlaces(int board[4][4])
{
	int row = findQueenRowPosition(board);
	int col = findQueenColPosition(board);
	for (int i = 0; i < 4; i++)
	{
		if (board[col][i] != 2)
		{
			board[col][i] = 1;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		if (board[i][row] != 2)
		{
			board[i][row] = 1;
		}
	}

	if (row == 0 and col == 0)
	{
		occupieBottomRightCorner(board, row, col);
	}
	else if (row == 0 and col != 0 and col != 3)
	{
		occupieBottomRightCorner(board, row, col);
		occupieTopRightCorner(board, row, col);
	}
	else if (col == 3 and row == 0)
	{
		occupieTopRightCorner(board, row, col);
	}
	else if (col == 3 and row != 0 and row !=3)
	{
		occupieTopRightCorner(board, row, col);
		occupieTopLeftCorner(board, row, col);
	}
	else if (row == 3 and col == 3)
	{
		occupieTopLeftCorner(board, row, col);
	}
	else if (row == 3 and col != 3 and col != 0)
	{
		occupieTopLeftCorner(board, row, col);
		occupieBottomLeftCorner(board, row, col);
	}
	else if (row == 3 and col == 0)
	{
		occupieBottomLeftCorner(board, row, col);
	}
	else if (col == 0 and row != 0 and row !=3)
	{
		occupieBottomLeftCorner(board, row, col);
		occupieBottomRightCorner(board, row, col);
	}

	return 0;
}

bool solver(int board[4][4])
{
	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 4; i++)
		{
			if (board[j][i] == 0)
			{
				board[j][i] = 2;
				break;
			}
		}
	}
	occupiePlaces(board);
	return 0;
}

void printTable(int board[4][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}


int main()
{
	int board[4][4] = { {0,0,0,0},
						{0,0,0,0},
						{0,0,0,0},
						{0,0,0,0} };
	for (int i = 0; i < 1; i++)
	{
		solver(board);
	}
	printTable(board);
}