/*
119. Pascal's Triangle II
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?
*/

#include<stdio.h>
#include<stdlib.h>

int* getRow(int rowIndex, int* returnSize) {
    int *row;
    int i,j;
    row = (int*)malloc(sizeof(int)*(rowIndex+1));
    for( i = 0; i <= rowIndex; i++ ){
		row[i] = 1;row[0] = 1;
		for( j = i-1; j > 0; j-- ){
			row[j] = row[j-1]+row[j];
		}
    }
    *returnSize = (rowIndex+1);
    return row;
}

int main()
{
	int rowIndex = 3;
	int returnSize;
	int *row = getRow(rowIndex,&returnSize);
	for( int i = 0; i < returnSize; i++ ){
		printf("%d\t",row[i]);
	}
}


