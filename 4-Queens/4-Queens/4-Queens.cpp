#include <iostream>
using namespace std;

int board[4][4] = { {0,0,0,0},
					{0,0,0,0},
					{0,0,0,0},
					{0,0,0,0} };
int fillerRow = 0;
int fillerCol = 0;
int solutions = 0;

int findQueenRowPosition(int j=0, int i=0)
{
	if (board[j][i] == 2)
	{
		return i;
	}
	if (i == 3)
	{
		i = 0;
		j++;
	}
	else {
		i++;
	}
	findQueenRowPosition(j,i);
}

int findQueenColPosition(int j = 0, int i = 0)
{
	if (board[j][i] == 2)
	{
		return j;
	}
	if (i == 3)
	{
		i = 0;
		j++;
	}
	else {
		i++;
	}
	findQueenColPosition(j, i);

}

void occupieTopRightCorner(int row,int col)
{
	int i = row, j = col;
	if (j < 0 or i > 3)
	{
		return;
	}
	else if ((j > 3 or i > 3) or (j < 0 or i < 0))
	{
		return;
	}
	board[j][i] = 1;
	occupieTopRightCorner(++i, --j);
}

void occupieTopLeftCorner(int row, int col)
{
	int i = row, j = col;
	if(j < 0 or i < 0)
	{
		return;
	}
	else if ((j > 3 or i > 3) or (j < 0 or i < 0))
	{
		return;
	}
	board[j][i] = 1;
	occupieTopLeftCorner(--i, --j);
}

void occupieBottomRightCorner(int row, int col)
{
	int i = row, j = col;
	if (j > 4 or i > 4)
	{
		return;
	}
	else if ((j > 3 or i > 3) or (j < 0 or i < 0))
	{
		return;
	}
	board[j][i] = 1;
	occupieBottomRightCorner(++i, ++j);
}

void occupieBottomLeftCorner(int row, int col)
{
	int i = row, j = col;
	if (j > 4 or i < 0)
	{
		return;
	}
	else if ((j > 3 or i > 3) or (j < 0 or i < 0))
	{
		return;
	}
	board[j][i] = 1;
	occupieBottomLeftCorner(--i, ++j);
}

void occupieHorizontal(int col, int i = 0)
{
	if (i == 4)
	{
		return;
	}
	board[col][i] = 1;
	occupieHorizontal(col, ++i);
}

void occpieVertical(int row, int i = 0)
{
	if (i == 4)
	{
		return;
	}
	board[i][row] = 1;
	occpieVertical(row, ++i);
}

void occupiePlaces()
{
	int row = findQueenRowPosition();
	int col = findQueenColPosition();
	
	occupieHorizontal(col);
	occpieVertical(row);

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
}

void printTable()
{
	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 4; i++)
		{
			cout << board[j][i] << " ";
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