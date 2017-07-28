/*
Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.
*/

#include<stdio.h>
int firstMissingPositive(int* nums, int numsSize) {
    int tmp,ntmp;
    if( numsSize == 0 ) return 1;
    if ( numsSize == 1 ){
		if( nums[0] != 1 ) return 1;
		else return 2;
    }
    for( int i = 0; i < numsSize; i++ ){
		tmp = nums[i];
		while( tmp > 0 && tmp <= numsSize && nums[tmp-1] != tmp){
			ntmp = nums[tmp-1];
			nums[tmp-1] = tmp;
			tmp = ntmp;
		}
    }
    for( int i = 0; i < numsSize; i++ ){
		if( nums[i] != i+1 ){
			return i+1;
		}
    }
    
    
    return numsSize+1;
}

int main()
{
	int nums[2] = {2,1};
	int res = firstMissingPositive(nums,2);
	printf("%d",res);
}

