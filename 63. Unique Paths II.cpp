/*
63. Unique Paths II

Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.
*/
#include<stdio.h> 
#include<stdlib.h>
int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridRowSize, int obstacleGridColSize) {
    int i,j;
    int **map;
    map = (int**)malloc(sizeof(int*)*obstacleGridRowSize*obstacleGridColSize);
    for( i = 0; i < obstacleGridRowSize; i++ ){
		*(map+i) = (int*)malloc(sizeof(int)*obstacleGridColSize);
    }
    for( i = 0; i < obstacleGridRowSize; i++ ){
		for( j = 0; j < obstacleGridColSize; j++ ){
			if( obstacleGrid[i][j] == 1 ){
				map[i][j] = 0;
			}else if( i == 0 || j == 0){
				if( i == 0 && j == 0 ) map[i][j] = 1;
				else if( i == 0 ) map[i][j] = map[i][j-1];
				else map[i][j] = map[i-1][j];
			}else{
				map[i][j] = map[i-1][j]+map[i][j-1];
			}
		}
    }
    return map[i-1][j-1];
}

int main()
{
	int **map;
	int m,n;
	m = 3;
	n = 3;
	map = (int**)malloc(sizeof(int*)*m);
	for( int i = 0; i < n; i++ ){
		*(map+i) = (int*)malloc(sizeof(int)*n);
	}
	map[0][0] = 0;map[0][1] = 0;map[0][2] = 0;
	map[1][0] = 0;map[1][1] = 1;map[1][2] = 0;
	map[2][0] = 0;map[2][1] = 0;map[2][2] = 0;
	int res = uniquePathsWithObstacles(map,m,n);
	printf("%d",res);
}


















