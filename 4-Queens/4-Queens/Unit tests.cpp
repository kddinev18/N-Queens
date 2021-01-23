#include <iostream>
#include "Global Variables.h"
#include "Data Layer.h"
using namespace std;

void testAreAllPositionsCreared()
{
	bool isClear = true;
	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 4; i++)
		{
			board[j][i] = 6;
		}
	}

	clearBoard();
	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 4; i++)
		{
			if (board[j][i] != 0)
			{
				isClear = false;
				break;
			}
		}
	}

	if (isClear)
	{
		cout << "Passed!" << endl;
	}

	else
	{
		cout << "Failed!" << endl;
	}

}

void testIsRowPositionCorrect()
{
	int rowPosition = 3;
	board[0][rowPosition] = 2;
	int recivedValue = findQueenRowPosition();
	if (rowPosition == recivedValue)
	{
		cout << "Passed!" << endl;
	}

	else
	{
		cout << "Failed" << endl;
	}
}

void testIsColumnPositionCorrect()
{
	int colPosition = 3;
	board[colPosition][0] = 2;
	int recivedValue = findQueenColPosition();
	if (colPosition == recivedValue)
	{
		cout << "Passed!" << endl;
	}

	else
	{
		cout << "Failed" << endl;
	}
}

void testAreCornersOccupied()
{
	int col = 0;
	int row = 3;
	int expectedRow = 0;
	int expectedCol = 3;
	board[col][row] = 2;
	occupyTopRightCorner(row, col);
	if (board[expectedCol][expectedRow] == 1)
	{
		cout << "Passed!" << endl;
	}

	else
	{
		cout << "Failed" << endl;
	}
}

void testIsHorizontallOccupied()
{
	int col = 2;
	bool isFilled = true;
	occupyHorizontal(col);
	for (int i = 0; i < 4; i++)
	{
		if (board[col][i] != 1)
		{
			isFilled = false;
			break;
		}
	}

	if(isFilled)
	{
		cout << "Passed!" << endl;
	}

	else
	{
		cout << "Failed" << endl;
	}
}

void testIsVerticalOccupied()
{
	int row = 2;
	bool isFilled = true;
	occupyVertical(row);
	for (int i = 0; i < 4; i++)
	{
		if (board[i][row] != 1)
		{
			isFilled = false;
			break;
		}
	}

	if (isFilled)
	{
		cout << "Passed!" << endl;
	}

	else
	{
		cout << "Failed" << endl;
	}
}

void testAreinvalidPositionFilled()
{
	int fillerRow = 3;
	int fillerCol = 0;
	bool isFilled = true;
	fillInvalidPositions(fillerRow, fillerCol);
	for (int j = 0; j < fillerCol; j++)
	{
		for (int i = 0; i < fillerRow; i++)
		{
			if (board[j][i] != 1)
			{
				isFilled = false;
			}
		}
	}

	if (isFilled)
	{
		cout << "Passed!" << endl;
	}

	else
	{
		cout << "Failed" << endl;
	}
}