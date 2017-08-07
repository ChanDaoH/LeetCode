/*
51. N-Queens
*/



#include<stdio.h>
#include<stdlib.h>
void helper(int n, int row, int* col, int** chess, int* size, int* ans, char*** res);
char*** solveNQueens(int n, int* returnSize) {
	int i, j;
	char ***res;
	res = (char***)malloc(sizeof(char**)*100);
	int row = 0, size = 0;
	int *col = (int*)malloc(sizeof(int)*n);
	int *ans = (int*)malloc(sizeof(int)*n);
	for (i = 0; i<n; i++) col[i] = 0;
	int **chess = (int**)malloc(sizeof(int*)*n);
	for (i = 0; i<n; i++) *(chess + i) = (int*)malloc(sizeof(int)*n);
	for (i = 0; i<n; i++) {
		for (j = 0; j<n; j++) {
			chess[i][j] = 0;
		}
	}

	helper(n, row, col, chess, &size, ans, res);

	*returnSize = size;
	return res;
}


void helper(int n, int row, int* col, int** chess, int* size, int* ans, char*** res) {
	int i, j;
	int x, y;
	bool tag = true;
	if (row >= n) {
		int k = *size;
		*(res + k) = (char**)malloc(sizeof(char*)*n);
		for (i = 0; i < n; i++) {
			res[k][i] = (char*)malloc(sizeof(char)*(n + 1));
		}
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				res[k][i][j] = '.';
			}
			res[k][i][n] = '\0';
		}
		for (i = 0; i < n; i++) {
			y = ans[i];
			res[k][i][y] = 'Q';
		}
		(*size)++;
		return;
	}

	for (i = 0; i < n; i++) {
		if (col[i]) continue;  //该列已被占用 
		tag = true; //重置斜方向冲突标记
		x = row; y = i;
		int u, v;
		if (x > y) {
			u = x - y; v = 0;
		}
		else {
			u = 0; v = y - x;
		}
		
		for (; u<n&&v<n; u++, v++) {
			if (chess[u][v]) {
				tag = false; break;
			}
		}
		if (!tag) continue; //斜方向有冲突 
		u = x; v = y;
		while (u < n-1 && v > 0) {
			u++; v--;
		}
		for (; u >= 0 && v < n; u--, v++) {
			if (chess[u][v]) {
				tag = false; break;
			}
		}
		if (!tag) continue; //斜方向有冲突 
		chess[row][i] = 1;
		col[i] = 1; //第i列被占用 
		ans[row] = i; //第row行的皇后位置在i列 
		helper(n, row + 1, col, chess, size, ans, res);
		chess[row][i] = 0;
		col[i] = 0;
		ans[row] = 0;
	}

	return;
}

int main()
{
	int n = 8;
	int size;
	char ***res;
	res = solveNQueens(n, &size);
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < n; j++) {
			printf("%s\n", res[i][j]);
		}
		printf("\n\n");
	}
}
