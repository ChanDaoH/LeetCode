/*
59. Spiral Matrix II
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/

#include<stdio.h>
#include<stdlib.h>

int** generateMatrix(int n) {
    int **matrix;
    int i,j,k,u,v;
    int size,num;
    matrix = (int**)malloc(sizeof(int*)*n);
    for( i = 0; i < n; i++ ){
		*(matrix+i) = (int*)malloc(sizeof(int)*n);
    }
    size = n*n;
    num = 1;
    
    for( i = 0; i < n; i++ ){
		for( j = i; j < n - i; j++ ){
			matrix[i][j] = num++;
		}
		j--;
		if( num > size ) break;
		for( k = i+1; k < n-i; k++ ){
			matrix[k][j] = num++;
		}
		k--;
		if( num > size ) break;
		for( u = n-2-i; u >= i; u-- ){
			matrix[k][u] = num++;
		}
		u++;
		if( num > size ) break;
		for( v = n-2-i; v > i; v-- ){
			matrix[v][u] = num++;
		}
		if( num > size ) break;
    }
    return matrix;
}

int main()
{
	int n = 3;
	int **matrix = generateMatrix(n);
	for( int i = 0; i < n; i++ ){
		for( int j = 0; j < n; j++ ){
			printf("%d\t",matrix[i][j]);
		}
		printf("\n");
	}
}

















