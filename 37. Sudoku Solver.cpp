/*
37. Sudoku Solver
*/


#include<stdio.h>
#include<stdlib.h>
bool solver(char** board, int row, int col, int** usedrow, int** usedcol, int** usedgrid);
void solveSudoku(char** board, int boardRowSize, int boardColSize) {
	int** usedrow, **usedcol, **usedgrid; //��¼����С���������ʹ����� 
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
			if (board[x][y] != '.') { //ÿ��ֻ���'.'���� 
				while ( x < 9 && board[x][y] != '.') {
					y++;
					if (y > 8) {
						x = row + 1; y = 0;
					}
				}
			}
			if (x > 8) return true;
			/*������һ������*/
			if (solver(board, x, y, usedrow, usedcol, usedgrid)) return true;
			/*��������ѡ��ʧ�ܣ�����ѡ��*/
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
	board[0][0] = '5'; board[0][1] = '3'; board[0][4] = '7';
	board[1][0] = '6'; board[1][3] = '1'; board[1][4] = '9'; board[1][5] = '5';
	board[2][1] = '9'; board[2][2] = '8'; board[2][7] = '6';
	board[3][0] = '8'; board[3][4] = '6'; board[3][8] = '3';
	board[4][0] = '4'; board[4][3] = '8'; board[4][5] = '3'; board[4][8] = '1';
	board[5][0] = '7'; board[5][4] = '2'; board[5][8] = '6';
	board[6][1] = '6'; board[6][6] = '2'; board[6][7] = '8';
	board[7][3] = '4'; board[7][4] = '1'; board[7][5] = '9'; board[7][8] = '5';
	board[8][4] = '8'; board[8][7] = '7'; board[8][8] = '9';
	solveSudoku(board, 9, 9);
	for (int i = 0; i < 9; i++) {
		printf("%s\n", board[i]);
	}
}

