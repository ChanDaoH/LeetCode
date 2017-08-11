/*
37. Sudoku Solver
*/


#include<stdio.h>
#include<stdlib.h>
bool solver(char** board, int row, int col, int** usedrow, int** usedcol, int** usedgrid);
void solveSudoku(char** board, int boardRowSize, int boardColSize) {
	int** usedrow, **usedcol, **usedgrid; //记录行列小矩阵的数字使用情况 
	usedrow = (int**)malloc(sizeof(int*) * 9);
	usedcol = (int**)malloc(sizeof(int*) * 9);
	usedgrid = (int**)malloc(sizeof(int*) * 9);
	for (int i = 0; i < 9; i++) {
		*(usedrow + i) = (int*)malloc(sizeof(int) * 9);
		*(usedcol + i) = (int*)malloc(sizeof(int) * 9);
		*(usedgrid + i) = (int*)malloc(sizeof(int) * 9);
	}
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			usedrow[i][j] = 0;
			usedcol[i][j] = 0;
			usedgrid[i][j] = 0;
		}
	}
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (board[i][j] != '.') {
				int num = board[i][j] - '0';
				usedrow[i][num - 1] = 1;
				usedcol[j][num - 1] = 1;
				usedgrid[i / 3 * 3 + j / 3][num - 1] = 1;
			}
		}
	}

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (board[i][j] == '.') {
				solver(board, i, j, usedrow, usedcol, usedgrid);
				return;
			}	
		}
	}
}

bool solver(char** board, int row, int col, int** usedrow, int** usedcol, int** usedgrid)
{
	if (row > 8) return true;
	

	for (int i = 0; i < 9; i++) {
		if (!usedrow[row][i] && !usedcol[col][i] && !usedgrid[row / 3 * 3 + col / 3][i]) {
			char ch = '0' + 1 + i;
			board[row][col] = ch;
			usedrow[row][i] = 1;
			usedcol[col][i] = 1;
			usedgrid[row / 3 * 3 + col / 3][i] = 1;
			int x, y;
			x = row;
			y = col + 1;
			if (y > 8) {
				x = row + 1; y = 0;
			}
			if (x > 8) return true;
			if (board[x][y] != '.') { //每次只填充'.'方格 
				while ( x < 9 && board[x][y] != '.') {
					y++;
					if (y > 8) {
						x = row + 1; y = 0;
					}
				}
			}
			if (x > 8) return true;
			/*进入下一个方格*/
			if (solver(board, x, y, usedrow, usedcol, usedgrid)) return true;
			/*本次数字选择失败，重新选择*/
			usedrow[row][i] = 0;
			usedcol[col][i] = 0;
			usedgrid[row / 3 * 3 + col / 3][i] = 0;
			board[row][col] = '.';
		}
	}
	return false;
}



int main()
{
	char **board = (char**)malloc(sizeof(char*) * 10);
	for (int i = 0; i < 9; i++) {
		*(board + i) = (char*)malloc(sizeof(char) * 10);
	}
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			board[i][j] = '.';
		}
		board[i][9] = '\0';
	}
	board[0][0] = '.'; board[0][1] = '3'; board[0][5] = '7';
	board[1][1] = '5'; board[1][3] = '4'; board[1][5] = '2'; board[1][7] = '9';board[1][8] = '8';
	board[2][2] = '2'; board[2][6] = '5';
	board[3][0] = '2'; board[3][1] = '9'; board[3][7] = '4';
	board[4][4] = '9'; 
	board[5][1] = '7'; board[5][7] = '6'; board[5][8] = '2';
	board[6][2] = '3'; board[6][6] = '7'; 
	board[7][0] = '1'; board[7][1] = '2'; board[7][3] = '5'; board[7][5] = '6';board[7][7] = '3';
	board[8][3] = '8'; board[8][7] = '2'; 
	solveSudoku(board, 9, 9);
	for (int i = 0; i < 9; i++) {
		printf("%s\n", board[i]);
	}
}

