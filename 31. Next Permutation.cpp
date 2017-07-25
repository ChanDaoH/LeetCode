#include<stdio.h>
#include<stdlib.h>
int cmpfunc(const void * a, const void * b);

void nextPermutation(int* nums, int numsSize) {
    int i,j,k;
    int tmp,size;
    int *p;
    for( i = numsSize-1; i >= 0; i-- ){
		for( j = numsSize-1; j >i; j-- ){
			if( nums[i] < nums[j] ){
				tmp = nums[i];
				nums[i] = nums[j];
				nums[j] = tmp;
				i++;
				size = numsSize - i;
				p = (int *)malloc(sizeof(int)*(size));
				for( k = 0; k < size; k++){
					p[k] = nums[k+i];
				}
				qsort(p,size,sizeof(int),cmpfunc);

				for( k = 0; k < size; k++ ){
					nums[k+i] = p[k];
				}
				return;
			}
		}
    }
	qsort(nums,numsSize,sizeof(int),cmpfunc);
}
int cmpfunc(const void * a, const void * b)
{
	return ( *(int*)a - *(int*)b );
}

int main()
{
	int nums[3] = {1,3,2};
	int numsSize = 3;
	nextPermutation(nums,numsSize);
	for( int i = 0; i < numsSize; i++ ){
		printf("%d ",nums[i]);
	}
}
