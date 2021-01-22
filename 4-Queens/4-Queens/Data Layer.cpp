#include <iostream>
#include "Global Variables.h"
using namespace std;

int findQueenRowPosition(int col = 0, int row = 0)
{
	// Bottom that return queen position on the row
	if (board[col][row] == 2)
	{
		return row;
	}

	// Go to the next column of we are in the end of the current column
	if (row == 3)
	{
		row = 0;
		col++;
	}

	// Go to the next position if we are not on the end of the row
	else {
		row++;
	}

	findQueenRowPosition(col, row);
}

int findQueenColPosition(int col = 0, int row = 0)
{
	// Bottom that return queen position on the column
	if (board[col][row] == 2)
	{
		return col;
	}

	// Go to the next column of we are in the end of the current column
	if (row == 3)
	{
		row = 0;
		col++;
	}

	// Go to the next position if we are not on the end of the row
	else {
		row++;
	}

	findQueenColPosition(col, row);
}

void occupyTopRightCorner(int row, int col)
{
	int i = row, j = col;
	// Bottom that stops the recursion if the column is less than 0 or the row is higher than 3
	if (j < 0 or i > 3)
	{
		return;
	}

	// Second bottom that stops the recursion is the positions are out of range
	else if ((j > 3 or i > 3) or (j < 0 or i < 0))
	{
		return;
	}

	board[j][i] = 1;
	occupyTopRightCorner(++i, --j);
}

void occupyTopLeftCorner(int row, int col)
{
	int i = row, j = col;
	// Bottom that stops the recursion if the column or the row are less than 0
	if (j < 0 or i < 0)
	{
		return;
	}

	// Second bottom that stops the recursion is the positions are out of range
	else if ((j > 3 or i > 3) or (j < 0 or i < 0))
	{
		return;
	}

	board[j][i] = 1;
	occupyTopLeftCorner(--i, --j);
}

void occupyBottomRightCorner(int row, int col)
{
	int i = row, j = col;
	// Bottom that stops the recursion if the column or the row are more than 4
	if (j > 4 or i > 4)
	{
		return;
	}

	// Second bottom that stops the recursion is the positions are out of range
	else if ((j > 3 or i > 3) or (j < 0 or i < 0))
	{
		return;
	}

	board[j][i] = 1;
	occupyBottomRightCorner(++i, ++j);
}

void occupyBottomLeftCorner(int row, int col)
{
	int i = row, j = col;
	// Bottom that stops the recursion if the column is more than 0 or the row is less than o
	if (j > 4 or i < 0)
	{
		return;
	}

	// Second bottom that stops the recursion is the positions are out of range
	else if ((j > 3 or i > 3) or (j < 0 or i < 0))
	{
		return;
	}

	board[j][i] = 1;
	occupyBottomLeftCorner(--i, ++j);
}

void occupyHorizontal(int col, int i = 0)
{
	// Bottom that stops the recusion if the row ends
	if (i == 4)
	{
		return;
	}

	board[col][i] = 1;
	occupyHorizontal(col, ++i);
}

void occupyVertical(int row, int i = 0)
{
	// Bottom that stops the recusion if the column ends
	if (i == 4)
	{
		return;
	}

	board[i][row] = 1;
	occupyVertical(row, ++i);
}

void occupyPlaces()
{
	int row = findQueenRowPosition();
	int col = findQueenColPosition();

	occupyHorizontal(col);
	occupyVertical(row);

	if (row == 0 and col == 0)
	{
		occupyBottomRightCorner(row, col);
	}

	else if (row == 0 and col != 0 and col != 3)
	{
		occupyBottomRightCorner(row, col);
		occupyTopRightCorner(row, col);
	}

	else if (col == 3 and row == 0)
	{
		occupyTopRightCorner(row, col);
	}

	else if (col == 3 and row != 0 and row != 3)
	{
		occupyTopRightCorner(row, col);
		occupyTopLeftCorner(row, col);
	}

	else if (row == 3 and col == 3)
	{
		occupyTopLeftCorner(row, col);
	}

	else if (row == 3 and col != 3 and col != 0)
	{
		occupyTopLeftCorner(row, col);
		occupyBottomLeftCorner(row, col);
	}

	else if (row == 3 and col == 0)
	{
		occupyBottomLeftCorner(row, col);
	}

	else if (col == 0 and row != 0 and row != 3)
	{
		occupyBottomLeftCorner(row, col);
		occupyBottomRightCorner(row, col);
	}

	else
	{
		occupyBottomLeftCorner(row, col);
		occupyBottomRightCorner(row, col);
		occupyTopLeftCorner(row, col);
		occupyTopRightCorner(row, col);
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

int clearBoard(int i = 0, int j = 0)
{
	// Bottom that stops the recusion if the column ends
	if (j >= 4)
	{
		return 0;
	}

	// Bottom that stops the recusion if the row ends
	if (i >= 4)
	{
		return 1;
	}

	board[i][j] = 0;
	if (clearBoard(i, j + 1) == 1)
	{
		return 1;
	}

	return clearBoard(i + 1, 0);
}

void fillInvalidPositions(int fillerRow, int fillerCol)
{
	for (int j = 0; j < fillerCol; j++)
	{
		for (int i = 0; i < fillerRow; i++)
		{
			board[j][i] = 1;
		}
	}
}

void solver(int fillerRow = 0, int fillerCol = 0)
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
				occupyPlaces();
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
			clearBoard();
			fillInvalidPositions(fillerRow, fillerCol);
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
			solver(fillerRow, fillerCol);
		}

	}
	//if all solutions are printed stop the function
	else {
		return;
	}

}