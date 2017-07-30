/*
48. Rotate Image
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?
*/
#include<stdio.h>
#include<stdlib.h>
void rotate(int** matrix, int matrixRowSize, int matrixColSize) {
    int i,j,k;
    int col,s,t,u,v,w;
    int row = (matrixRowSize+1)/2;
    for( i = 0; i < row; i++ ){
		u = i;
		col = matrixColSize-1-i;
		for( j = i; j < col; j++ ){
			v = j;
			s = matrix[matrixColSize-1-j][i];
			for( k = 0; k < 4; k++ ){
				t = matrix[u][v];
				matrix[u][v] = s;
				s = t;
				w = v;
				v = matrixColSize-1-u;
				u = w;
			}
		}
    }
}

int main()
{
	int** matrix;
	int matrixRowSize = 4;
	matrix = (int**)malloc(sizeof(int*)*matrixRowSize);
	for( int i = 0; i < matrixRowSize; i++ ){
		*(matrix + i) = (int*)malloc(sizeof(int)*matrixRowSize);
	}
	matrix[0][0] =1 ;matrix[0][1] = 2;matrix[0][2] = 3;matrix[0][3] = 4;
	matrix[1][0] =5 ;matrix[1][1] = 6;matrix[1][2] = 7;matrix[1][3] = 8;
	matrix[2][0] =9 ;matrix[2][1] = 10;matrix[2][2] = 11;matrix[2][3] = 12;
	matrix[3][0] =13 ;matrix[3][1] = 14;matrix[3][2] = 15;matrix[3][3] = 16;
	rotate(matrix,matrixRowSize,matrixRowSize);
	for( int i = 0; i < matrixRowSize; i++ ){
		for( int j = 0; j < matrixRowSize; j++ ){
			printf("%d\t",matrix[i][j]);
		}
		printf("\n");
	}
	
}
