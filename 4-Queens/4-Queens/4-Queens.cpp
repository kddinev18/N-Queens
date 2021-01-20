#include <iostream>
using namespace std;

int board[4][4] = { {0,0,0,0},
					{0,0,0,0},
					{0,0,0,0},
					{0,0,0,0} };
int fillerRow = 0;
int fillerCol = 0;
int solutions = 0;

int findQueenRowPosition()
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

int findQueenColPosition()
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

void occupieTopRightCorner(int row,int col)
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

void occupieTopLeftCorner(int row, int col)
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

void occupieBottomRightCorner(int row, int col)
{
	int i = row, j = col;
	while (i != 4 or j != 4)
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

void occupieBottomLeftCorner(int row, int col)
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

int occupiePlaces()
{
	int row = findQueenRowPosition();
	int col = findQueenColPosition();
	for (int i = 0; i < 4; i++)
	{
		board[col][i] = 1;
	}
	for (int i = 0; i < 4; i++)
	{
		board[i][row] = 1;
	}

	if (row == 0 and col == 0)
	{
		occupieBottomRightCorner(row, col);
	}
	else if (row == 0 and col != 0 and col != 3)
	{
		occupieBottomRightCorner(row, col);
		occupieTopRightCorner(row, col);
	}
	else if (col == 3 and row == 0)
	{
		occupieTopRightCorner(row, col);
	}
	else if (col == 3 and row != 0 and row !=3)
	{
		occupieTopRightCorner(row, col);
		occupieTopLeftCorner(row, col);
	}
	else if (row == 3 and col == 3)
	{
		occupieTopLeftCorner(row, col);
	}
	else if (row == 3 and col != 3 and col != 0)
	{
		occupieTopLeftCorner(row, col);
		occupieBottomLeftCorner(row, col);
	}
	else if (row == 3 and col == 0)
	{
		occupieBottomLeftCorner(row, col);
	}
	else if (col == 0 and row != 0 and row !=3)
	{
		occupieBottomLeftCorner(row, col);
		occupieBottomRightCorner(row, col);
	}
	else
	{
		occupieBottomLeftCorner(row, col);
		occupieBottomRightCorner(row, col);
		occupieTopLeftCorner(row, col);
		occupieTopRightCorner(row, col);
	}

	board[col][row] = 3;
	return 0;
}

void reset()
{
	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 4; i++)
		{
			board[j][i] = 0;
		}
	}
}

void printTable()
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

void clear()
{
	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 4; i++)
		{
			board[j][i] = 0;
		}
	}
}

void filler()
{
	for (int j = 0; j< fillerCol; j++)
	{
		for (int i = 0; i < fillerRow; i++)
		{
			board[j][i] = 1;
		}
	}
}

void solver()
{
	int queens = 0;
	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 4; i++)
		{
			if (board[j][i] == 0)
			{
				board[j][i] = 2;
				occupiePlaces();
				queens++;
			}
		}
	}
	if (solutions != 2)
	{
		if (queens != 4)
		{
			clear();
			filler();
			fillerRow++;
			if (fillerRow == 4)
			{
				fillerRow = 0;
				fillerCol++;
			}
			queens = 0;
			solver();
		}
		else {
			printTable();
			cout << endl;
			queens = 0;
			solutions++;
			solver();
		}
	}
	else {
		return;
	}
}

int main()
{
	solver();
}