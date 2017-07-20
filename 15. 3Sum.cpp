#include<stdio.h>
#include<stdlib.h>

int cmpfunc(const void * a, const void * b);

int** threeSum(int* nums, int numsSize, int* returnSize) {
	int k;
	int min,mid,max;
	int **p;
	int sum,tmp;
	int lt,rt;
	int i = 0;
	p = (int**)malloc(sizeof(int*)*100);
	*returnSize = 0;
    qsort(nums,numsSize,sizeof(int),cmpfunc);
    for( k = 0; k < numsSize - 2;  k++ ){
		min = k+1;
		max = numsSize - 1;
		while( min < max ){
			tmp = nums[k]+nums[min]+nums[max];
			if(tmp == 0 ){
				*(p+i) = (int*)malloc(sizeof(int)*3);
				p[i][0] = nums[k];
				p[i][1] = nums[min];
				p[i][2] = nums[max];
				i++;
				while( nums[min] == nums[min+1] ){
					min++;
				}
				while( nums[max] == nums[max-1]){
					max--;
				}
				min++;max--;
			}else if( tmp < 0 ){
				min++;
			}else{
				max--;
			}
		}
		while( nums[k] == nums[k+1] ){
			k++;
		}
	}
    *returnSize = i;
    return p;
}



int cmpfunc(const void * a, const void * b)
{
	return ( *(int*)a - *(int*)b );
}

int main()
{
	int nums[6] = {-1,0,1,2,-1,-4};
	int **p;
	int a;
	p = threeSum(nums,6,&a);
	for( int i = 0; i < a; i++ ){
		printf("[%d,%d,%d]\n",p[i][0],p[i][1],p[i][2]);
		
	}
}
