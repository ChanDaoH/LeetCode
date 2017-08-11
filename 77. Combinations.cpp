/*
77. Combinations
*/

#include<stdio.h>
#include<stdlib.h>
void helper(int nums, int n, int k, int count, int *subset,int*columnSizes ,int *size,int **res);
int** combine(int n, int k, int** columnSizes, int* returnSize) {
    int *subset = (int*)malloc(sizeof(int)*k);
    (*columnSizes) = (int*)malloc(sizeof(int)*10000);
    int count=0,size=0,start = 0;
    int **res = (int**)malloc(sizeof(int*)*10000);

    helper(start,n,k,count,subset,*columnSizes,&size,res);
    *returnSize = size;
    return res;
}

void helper(int start, int n, int k, int count, int *subset,int*columnSizes, int *size,int **res)
{
	int i;
	if(count>=k){
		int s = *size;
		res[s] = (int*)malloc(sizeof(int)*k);
		columnSizes[s] = k;
		for( i = 0; i < k; i++ ){
			res[s][i] = subset[i];
		}
		(*size)++;
		return;
	}
	/*dfs*/
	for( i = start; i < n; i++ ){
		if( k-count > n-i ){ /*后续数字数量不够 返回*/
			return;
		}
		subset[count++] = i+1;
		helper(i+1,n,k,count,subset,columnSizes,size,res);
		count--;
	}
}

int main()
{
	int n = 4;
	int k = 2;
	int *columnSizes;
	int size;
	int **res;
	res = combine(n,k,&columnSizes,&size);
	for( int i = 0; i < size; i++ ){
		for( int j = 0; j < k; j++ ){
			printf("%d\t",res[i][j]);
		}
		printf("\n");
	}
}
