/*
118. Pascal's Triangle
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/
#include<stdio.h>
#include<stdlib.h>
int** generate(int numRows, int** columnSizes) {
    int i,j;
    int n;
    int **matrix;
    (*columnSizes) = (int*)malloc(sizeof(int)*numRows);
    if ( numRows <= 0 ){
        
        return NULL;
    } 
    matrix = (int**)malloc(sizeof(int*)*numRows);
    for( i = 0; i < numRows; i++ ){
		*(matrix+i) = (int*)malloc(sizeof(int)*(i+1));
		(*columnSizes)[i] = i+1;
    }
    matrix[0][0] = 1;
    for( i = 1; i < numRows; i++ ){
		matrix[i][0] = 1;
		for( j = 1; j < i; j++ ){
			matrix[i][j] = matrix[i-1][j-1]+matrix[i-1][j];
		}
		matrix[i][j] = 1;
    }
    return matrix;
}

int main()
{
	int numRows = 5;
	int **matrix, *columnSizes;
	matrix = generate(numRows,&columnSizes);
	for( int i = 0; i < numRows; i++ ){
		for( int j = 0; j < columnSizes[i]; j++ ){
			printf("%d\t",matrix[i][j]);
		}
		printf("\n");
	}
	
}
















