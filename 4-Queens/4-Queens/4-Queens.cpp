#include <iostream>
using namespace std;

//chess board
int board[4][4] = { {0,0,0,0},
					{0,0,0,0},
					{0,0,0,0},
					{0,0,0,0} };
int solutions = 0;

int findQueenRowPosition(int col = 0, int row = 0)
{
	//bottom that return queen position on the row
	if (board[col][row] == 2)
	{
		return row;
	}
	//go to the next column of we are in the end of the current column
	if (row == 3)
	{
		row = 0;
		col++;
	}
	//go to the next position if we are not on the end of the row
	else {
		row++;
	}
	findQueenRowPosition(col, row);
}

int findQueenColPosition(int col = 0, int row = 0)
{
	//bottom that return queen position on the column
	if (board[col][row] == 2)
	{
		return col;
	}
	//go to the next column of we are in the end of the current column
	if (row == 3)
	{
		row = 0;
		col++;
	}
	//go to the next position if we are not on the end of the row
	else {
		row++;
	}
	findQueenColPosition(col, row);

}

void occupieTopRightCorner(int row,int col)
{
	int i = row, j = col;
	//bottom that stops the recursion if the column is less than 0 or the row is higher than 3
	if (j < 0 or i > 3)
	{
		return;
	}
	//second bottom that stops the recursion is the positions are out of range
	else if ((j > 3 or i > 3) or (j < 0 or i < 0))
	{
		return;
	}
	board[j][i] = 1;
	//function calls it self with arguments: row+1 and column-1
	occupieTopRightCorner(++i, --j);
}

void occupieTopLeftCorner(int row, int col)
{
	int i = row, j = col;
	//bottom that stops the recursion if the column or the row are less than 0
	if(j < 0 or i < 0)
	{
		return;
	}
	//second bottom that stops the recursion is the positions are out of range
	else if ((j > 3 or i > 3) or (j < 0 or i < 0))
	{
		return;
	}
	board[j][i] = 1;
	//function calls it self with arguments: row-1 and column-1
	occupieTopLeftCorner(--i, --j);
}

void occupieBottomRightCorner(int row, int col)
{
	int i = row, j = col;
	//bottom that stops the recursion if the column or the row are more than 4
	if (j > 4 or i > 4)
	{
		return;
	}
	//second bottom that stops the recursion is the positions are out of range
	else if ((j > 3 or i > 3) or (j < 0 or i < 0))
	{
		return;
	}
	board[j][i] = 1;
	//function calls it self with arguments: row+1 and column+1
	occupieBottomRightCorner(++i, ++j);
}

void occupieBottomLeftCorner(int row, int col)
{
	int i = row, j = col;
	//bottom that stops the recursion if the column is more than 0 or the row is less than o
	if (j > 4 or i < 0)
	{
		return;
	}
	//second bottom that stops the recursion is the positions are out of range
	else if ((j > 3 or i > 3) or (j < 0 or i < 0))
	{
		return;
	}
	board[j][i] = 1;
	//function calls it self with arguments: row-1 and column+1
	occupieBottomLeftCorner(--i, ++j);
}

void occupieHorizontal(int col, int i = 0)
{
	//bottom that stops the recusion if the row ends
	if (i == 4)
	{
		return;
	}
	board[col][i] = 1;
	//function calls it self with arguments: the same column and row+1
	occupieHorizontal(col, ++i);
}

void occpieVertical(int row, int i = 0)
{
	//bottom that stops the recusion if the column ends
	if (i == 4)
	{
		return;
	}
	//function calls it self with arguments: the same row and column+1
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
	cout << endl;
}

//clean up the board
int clear(int i = 0, int j = 0)
{
	//bottom that stops the recusion if the column ends
	if (j >= 4)
	{
		return 0;
	}
	//bottom that stops the recusion if the row ends
	if (i >= 4)
	{
		return 1;
	}
	board[i][j] = 0;
	if (clear(i, j + 1) == 1)
	{
		return 1;
	}
	return clear(i + 1, 0);
}

//fill the positions that aren't valid
void filler(int fillerRow, int fillerCol)
{
	for (int j = 0; j < fillerCol; j++)
	{
		for (int i = 0; i < fillerRow; i++)
		{
			board[j][i] = 1;
		}
	}
}

void solver(int fillerRow=0, int fillerCol=0)
{
	int queens = 0;
	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 4; i++)
		{
			//occipie the first fre place
			if (board[j][i] == 0)
			{
				board[j][i] = 2;
				occupiePlaces();
				queens++;
			}
		}
	}
	//if all solutions aren't printed
	if (solutions != 2)
	{
		//if there are less than for queens on the board
		if (queens != 4)
		{
			clear();
			filler(fillerRow, fillerCol);
			queens = 0;
			fillerRow++;
			//if we are in te end of the row go to the next column
			if (fillerRow == 4)
			{
				fillerRow = 0;
				fillerCol++;
			}
			//function calls it self
			solver(fillerRow, fillerCol);
		}
		//if there are 4 queens on the board
		else {
			queens = 0;
			//increase the solutions
			solutions++;
			printTable();
			//function calls it self
			solver(fillerRow,fillerCol);
		}
	}
	//if all solutions are printed stop the function
	else {
		return;
	}
}

int main()
{
	solver();
}