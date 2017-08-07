/*
47. Permutations II
*/


#include<stdio.h>
#include<stdlib.h>
int cmpfunc(const void * a, const void * b );
void helper(int* nums, int numsSize, int* s, int count, int* subset, int* size, int** res);
int** permuteUnique(int* nums, int numsSize, int* returnSize) {
	int **res,*subset,*s;
    int size,count;	    
    
    size=count=0;
    res = (int**)malloc(sizeof(int*)*100);
    subset = (int*)malloc(sizeof(int)*numsSize);
    s = (int*)malloc(sizeof(int)*numsSize);
    for( int i = 0; i < numsSize; i++ ){
		s[i] = 0;
    }
    qsort(nums,numsSize,sizeof(int),cmpfunc);
    helper(nums,numsSize,s,count,subset,&size,res);
    
    *returnSize = size;
    return res;
}

void helper(int* nums, int numsSize, int* s, int count, int* subset, int* size, int** res){
	int i;
	if( count == numsSize ){
		int k = *size;
		*(res+k) = (int*)malloc(sizeof(int)*count);
		for( i = 0; i < count; i++ ){
			res[k][i] = subset[i];
		}
		(*size)++;
		return;
	}
	
	for( i = 0; i < numsSize; i++ ){
		if( !s[i] ){
			subset[count++] = nums[i];
			s[i] = 1;
			helper(nums,numsSize,s,count,subset,size,res);
			count--;
			s[i] = 0;
			
			/*ÅÅ³ýÖØ¸´*/
			while( i < numsSize-1 && nums[i] == nums[i+1] ) i++;
		}
	}
}

int cmpfunc(const void * a, const void * b )
{
	return ( *(int*)a - *(int*)b );
}

int main()
{
	int nums[3] = {1,1,2};
	int numsSize = 3;
	int size;
	int **res;
	res = permuteUnique(nums,numsSize,&size);
	for( int i = 0; i < size; i++ ){
		for( int j = 0; j < numsSize; j++ ){
			printf("%d\t",res[i][j]);
		}
		printf("\n");
	}
}

