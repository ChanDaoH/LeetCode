/*
53. Maximum Subarray
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.
*/

#include<stdio.h>
int maxSubArray(int* nums, int numsSize) {
    int res; //结果
	int sum; //累加和
	if( numsSize == 0 ) return 0;
	if( numsSize == 1 ) return nums[0];
	res = -2147483648;
	sum = 0;
	for( int i = 0; i < numsSize; i++ ){
		sum += nums[i];
		if( sum > res ) res = sum;
		if( sum < 0 ) sum = 0;
	} 
	return res;
}

int main()
{
	int nums[1] = {-2};
	int numsSize = 1;
	int res = maxSubArray(nums,numsSize);
	printf("%d",res);
}
