/*
78. Subsets
*/

#include<stdio.h>
#include<stdlib.h>

void helper( int** res, int* subset, int* size, int count, int* columnSizes, int* nums, int numsSize, int start );
int cmpfunc(const void * a, const void * b);
int** subsets(int* nums, int numsSize, int** columnSizes, int* returnSize) {
    int size,count,start;
    int *subset,**res;
	size=count=start=0;
    
    subset = (int*)malloc(sizeof(int)*numsSize);
    res = (int**)malloc(sizeof(int)*(1<<numsSize));
    (*columnSizes) = (int*)malloc(sizeof(int)*(1<<numsSize));
    qsort(nums,numsSize,sizeof(int),cmpfunc);	//从小到大排序 
    
    
    helper(res,subset,&size,count,*columnSizes,nums,numsSize,start);
    *returnSize = size;
    return res;
}


void helper( int** res, int* subset, int* size, int count, int* columnSizes, int* nums, int numsSize, int start )
{
	//将子集添加到结果集中
	int s = *size;
	columnSizes[s] = count;
	*(res+s) = (int*)malloc(sizeof(int)*count);
	for( int m = 0; m < count; m++ ){
		res[s][m] = subset[m];
	} 
	(*size)++;
	
	for( int i = start; i < numsSize; i++ ){	//DFS其余节点 
		subset[count++] = nums[i];
		helper(res,subset,size,count,columnSizes,nums,numsSize,i+1);
		count--;
	}
}

int cmpfunc(const void * a, const void * b)
{
	return ( *(int*)a - *(int*)b );
}

int main()
{
	int nums[3] = {1,2,3};
	int numsSize = 3;
	int *columnSizes;
	int returnSize;
	int **res = subsets(nums,numsSize,&columnSizes,&returnSize);
	for( int i = 0; i < returnSize; i++ ){
		for( int j = 0; j < columnSizes[i]; j++ ){
			printf("%d\t",res[i][j]);
		}
		printf("\n");
	}
}
