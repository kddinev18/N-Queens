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



