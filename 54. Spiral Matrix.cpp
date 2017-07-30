/*
54. Spiral Matrix
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].
*/

#include<stdio.h>
#include<malloc.h>
int* spiralOrder(int** matrix, int matrixRowSize, int matrixColSize) {
    int *res;
    int time;
    int len;
    int i,j,k,u,v;
    time = 0;
    len = matrixRowSize*matrixColSize;
    res = (int *)malloc(sizeof(int)*len);
    for(  i = 0; i < matrixRowSize; i++ ){
		for(  j = i; j < matrixColSize-i; j++ ){	//->
			res[time++] = matrix[i][j];
		}
		j--;
		if( time >= len ) return res;
		for(  k = i+1; k < matrixRowSize - i; k++ ){	//|
			res[time++] = matrix[k][j];
		}
		if( time >= len ) return res;
		k--;
		for(  u = matrixColSize-2-i; u >=  i; u-- ){	//<-
			res[time++] = matrix[k][u];
		}
		if( time >= len ) return res;
		u++;
		for(  v = matrixRowSize-2-i; v > i; v-- ){	//|
			res[time++] = matrix[v][u];
		}
		if( time >= len ) return res;
    }
}

int main()
{
	int **matrix;
	int matrixRowSize,matrixColSize,len;
	int *res;
	matrixRowSize = 3;
	matrixColSize = 3;
	len = matrixRowSize*matrixColSize;
	matrix = (int**)malloc(sizeof(int*)*matrixRowSize);
	for( int i = 0; i < matrixRowSize; i++ ){
		*(matrix+i) = (int*)malloc(sizeof(int)*matrixColSize);
	}
	matrix[0][0] = 1;matrix[0][1] = 2;matrix[0][2] = 3;
	matrix[1][0] = 8;matrix[1][1] = 9;matrix[1][2] = 4;
	matrix[2][0] = 7;matrix[2][1] = 6;matrix[2][2] = 5;
	res = spiralOrder(matrix,matrixRowSize,matrixColSize);
	for( int i = 0; i < len; i++ ){
		printf("%d ",res[i]);
	}
	
}
