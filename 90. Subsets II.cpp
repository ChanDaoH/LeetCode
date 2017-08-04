/*
90. Subsets II
*/

#include<stdio.h>
#include<stdlib.h>

int cmpfunc(const void * a, const void * b);
void dfs(int* nums,int numsSize,int* columnSizes,int* subset, int start, int* size, int count, int** res);

int** subsetsWithDup(int* nums, int numsSize, int** columnSizes, int* returnSize)  {
    int** res;
    int* subset;
    int size;
    int count,start;
    
    size = count = start = 0;
    subset = (int*)malloc(sizeof(int)*numsSize);
    res = (int**)malloc(sizeof(int*)*(1<<numsSize));
    (*columnSizes) = (int*)malloc(sizeof(int)*(1<<numsSize));
    
    qsort(nums,numsSize,sizeof(int),cmpfunc);
    
    dfs(nums,numsSize,*columnSizes,subset,start,&size,count,res);
    
    *returnSize = size;
    return res;
}

void dfs(int* nums,int numsSize,int* columnSizes,int* subset, int start, int* size, int count, int** res){
	int i,k;
	/*将当前子集添加到结果集*/
	k = *size;
	columnSizes[k] = count;
	*(res+k) = (int*)malloc(sizeof(int)*count);
	for( i = 0; i < count; i++ ){
		res[k][i] = subset[i];
	}
	(*size)++;
	
	for( i = start; i < numsSize; i++ ){
		subset[count++] = nums[i];
		dfs(nums,numsSize,columnSizes,subset,i+1,size,count,res);
		count--;
		while( i < numsSize-1 && nums[i] == nums[i+1] ) i++; //排除同一层的重复访问 
	}
	
}

int cmpfunc(const void * a, const void * b)
{
	return ( *(int*)a - *(int*)b );
}

int main()
{
	int nums[4] = {1,2,2,3};
	int numsSize = 4;
	int size;
	int *columnSizes, **res;
	res = subsetsWithDup(nums,numsSize,&columnSizes,&size);
	for( int i = 0; i < size; i++ ){
		for( int j = 0; j < columnSizes[i]; j++ ){
			printf("%d\t",res[i][j]);
		}
		printf("\n");
	}
}















