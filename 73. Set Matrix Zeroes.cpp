/*
73. Set Matrix Zeroes

Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

click to show follow up.

Follow up:
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?

*/

#include<stdio.h>
#include<stdlib.h>

void setZeroes(int** matrix, int matrixRowSize, int matrixColSize) {
    int* row;
    int* col;
    int i,j;
    row = (int*)malloc(sizeof(int)*matrixRowSize);
    col = (int*)malloc(sizeof(int)*matrixColSize);
    for( i = 0; i < matrixRowSize; i++ ){
		row[i] = 0;
    }
    for( j = 0; j < matrixColSize; j++ ){
		col[j] = 0;
    }
    for( i = 0; i < matrixRowSize; i++ ){
		for( j = 0; j < matrixColSize; j++ ){
			if( matrix[i][j] == 0 ){
				row[i] = 1;
				col[j] = 1;
			}
		}
    }
    for( i = 0; i < matrixRowSize; i++ ){
		if( row[i] == 1 ){
			for( j = 0; j < matrixColSize; j++ ){
				matrix[i][j] = 0;
			}
		}
    }
    for( j = 0; j < matrixColSize; j++ ){
		if( col[j] == 1 ){
			for( i = 0; i < matrixRowSize; i++ ){
				matrix[i][j] = 0;
			}
		}
    }
}























