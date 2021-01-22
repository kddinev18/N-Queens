#pragma once
using namespace std;

int findQueenRowPosition(int col = 0, int row = 0);
int findQueenColPosition(int col = 0, int row = 0);
void occupyTopRightCorner(int row, int col);
void occupyTopLeftCorner(int row, int col);
void occupyBottomRightCorner(int row, int col);
void occupyBottomLeftCorner(int row, int col);
void occupyHorizontal(int col, int i = 0);
void occupyVertical(int row, int i = 0);
void occupyPlaces();
void printTable();
int clearBoard(int i = 0, int j = 0);
void fillInvalidPositions(int fillerRow, int fillerCol);
void solver(int fillerRow = 0, int fillerCol = 0);