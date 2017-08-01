/*
62. Unique Paths
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?
*/

#include<stdio.h>
#include<stdlib.h>

int uniquePaths(int m, int n) {
    int **map;
    int i,j;
    map = (int**)malloc(sizeof(int*)*m);
    for( i = 0; i < m; i++ ){
		*(map+i) = (int*)malloc(sizeof(int)*n);
    }
    
    for( i = 0; i < m; i++ ){
		for( j = 0; j < n; j++ ){
			if( i == 0 || j == 0 ){
				map[i][j] = 1;
			}else{
				map[i][j] = map[i][j-1] + map[i-1][j];
			}
		}
    }
    return map[m-1][n-1];
}

int main()
{
	int count = uniquePaths(3,2);
	printf("%d",count);
}






















