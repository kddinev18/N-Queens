#include <iostream>
using namespace std;

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


int findQueenRowPosition(int board[4][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (board[i][j] == 2)
			{
				return i;
			}
		}
	}
}

int findQueenColPosition(int board[4][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (board[i][j] == 2)
			{
				return j;
			}
		}
	}
}

int occupiePlaces(int board[4][4])
{
	int row = findQueenRowPosition(board);
	int col = findQueenColPosition(board);
	for (int i = 0; i < 4; i++)
	{
		board[col][i] = 1;
	}
	for (int i = 0; i < 4; i++)
	{
		board[i][row] = 1;
	}
	return 0;
}

bool solver(int board[4][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (board[i][j] == 0)
			{
				board[i][j] = 2;
				break;
			}
		}
	}
	occupiePlaces(board);
	return 0;
}

int main()
{
	int board[4][4] = { {0,0,0,0},
						{0,0,0,0},
						{0,0,0,0},
						{0,0,0,0} };
	solver(board);
	printTable(board);
}