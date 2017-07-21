#include<stdio.h>
#include<stdlib.h>

int cmpfunc(const void * a, const void * b);

int* twoSum(int* nums, int numsSize, int target) {
    int min,max; //左右指针
    int *res;
    int tmp;
    int m,n;
    int* copynums;
	min = 0;
	max = numsSize-1; 
	res = (int *)malloc(sizeof(int)*2);
	copynums = (int *)malloc(sizeof(int)*numsSize);
	for( int j = 0; j < numsSize; j++ )
		copynums[j] = nums[j];
	//从小到大排序
	qsort(nums,numsSize,sizeof(int),cmpfunc);
	while(min<max){
		tmp = nums[min] + nums[max];
		if( tmp == target ){
			int tmpmin,tmpmax;
			tmpmin = nums[min];
			tmpmax = nums[max];
			for( m = 0; m < numsSize; m++ ){
				if( copynums[m] == tmpmin ){
					res[0] = m;
					break;
				}
			}
			for( int n = 0; n < numsSize; n++ ){
				if( m!=n && copynums[n] == tmpmax ){
					res[1] = n;
					break;
				}
			}
			return res;
		}else if( tmp < target ){	//左指针朝大方向移动 
			while(nums[min]==nums[min+1]){
				min++;
			}
			min++;
		}else{	//右指针朝小方向移动 
			while(nums[max]==nums[max-1]){
				max--;
			}
			max--;
		}
	} 
	return res;
}

int cmpfunc(const void * a, const void * b)
{
	return ( *(int*)a - *(int*)b );
}

int main()
{
	int nums[2] = {3,3};
	int *a;
	a = twoSum(nums,2,6);
	printf("[%d,%d]",a[0],a[1]);
}
