/*
64. Minimum Path Sum

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/

#include<stdio.h>
#include<stdlib.h>

int minPathSum(int** grid, int gridRowSize, int gridColSize) {
    int** map;
    int m,n;
    int i,j;
    
    map = (int**)malloc(sizeof(int*)*gridRowSize);
    for( i = 0; i < gridRowSize; i++ ){
		*(map+i) = (int*)malloc(sizeof(int)*gridColSize);
    }
    
    for( i = 0; i < gridRowSize; i++ ){
		for( j = 0; j < gridColSize; j++ ){
			if ( i == 0 && j == 0 )
				map[i][j] = grid[0][0];
			else if( i == 0 )
				map[i][j] = grid[i][j] + map[i][j-1];
			else if( j == 0 )
				map[i][j] = grid[i][j] + map[i-1][j];
			else{
				m = map[i-1][j];
				n = map[i][j-1];
				map[i][j] = grid[i][j] + (m<n?m:n);
			}
				
		}
    }
    return map[gridRowSize-1][gridColSize-1];    
}

int main()
{
	int** map;
	int m,n;
	map = (int**)malloc(sizeof(int*)*m);
	for( int i = 0; i < m; i++ ){
		*(map+i) = (int*)malloc(sizeof(int)*n);
	}
	map[0][0] = 1; map[0][1] = 2;
	map[1][0] = 1; map[1][1] = 1;
	m = 2; 
	n = 2;
	int res = minPathSum(map,m,n);
	printf("%d",res);
}




