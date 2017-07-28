#include<stdio.h>
#include<malloc.h>

void dfs(int* nums, int numsSize, int target, int start, int *p,int count, int* columnSizes,int** res,int* size);
int cmpfunc(const void * a, const void * b);

int** combinationSum(int* candidates, int candidatesSize, int target, int** columnSizes, int* returnSize) {
	int start,count,size; //countΪÿ�ν���ļ�������sizeΪ��������ļ����� 
	int *p;
	int **res;
	start=count=size = 0;

	p =(int *)malloc(sizeof(int)*200);	//��ŵ�ǰ���ۼ������� 
    res = (int**)malloc(sizeof(int*)*200);	//��� 
    (*columnSizes)=(int*)malloc(sizeof(int)*200);	//һά���飬ÿ����������ĸ��� 
    qsort(candidates,candidatesSize,sizeof(int),cmpfunc);	//��С�������� 
    
    dfs(candidates,candidatesSize,target,start,p,count,*columnSizes,res,&size); //����������� 
    
	*returnSize = size;
    return res;
}

void dfs(int* nums, int numsSize, int target, int start, int *p,int count, int* columnSizes,int** res,int* size)
{
	if( target < 0 ){	//��ǰ·�������ܵõ�Ŀ��ֵ 
		return;
	}
	if( target == 0 ){	//�ѵõ�Ŀ��ֵ ,������������ 
		int s = *size;
		columnSizes[s] = count;
		*(res+s) = (int*)malloc(sizeof(int)*count);
		for( int m = 0; m < count; m++ )
			res[s][m] = p[m];
		(*size)++;
		return;
	}
	for( int i = start; i< numsSize; i++ ){
		p[count++] = nums[i]; //���ν����֧
		dfs(nums,numsSize,target - nums[i],i,p,count,columnSizes,res,size);
		count--; 
	}
}

int cmpfunc(const void * a, const void * b)
{
	return ( *(int*)a - *(int*)b );
}

int main()
{
	int nums[7] = {5,10,8,4,3,12,9};
	int target = 27;
	int **res;
	int returnSize;	
	int *columnSize;
	res = combinationSum(nums,7,target,&columnSize,&returnSize);
	for( int i = 0; i < returnSize; i++ ){
		for( int j = 0; j < columnSize[i]; j++ ){
			printf("%d ",res[i][j]);
		}
		printf("\n");
	}

}

