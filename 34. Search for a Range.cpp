/*
Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/

#include<stdio.h>
#include<stdlib.h>
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int i = 0;
    int j = numsSize - 1;
    int mid;  
    int tmp;
    int *p;
    int size;
    *returnSize = 2; 
    p = (int *)malloc(sizeof(int)*2);
    while( i<= j ){
		mid = (i+j)/2;
		tmp = nums[mid];
		if(tmp == target){
			i=j=mid;
			while(i>=0&&nums[i]==target) i--;
			while(j<=numsSize-1&&nums[j]==target) j++;
			p[0] = i+1;
			p[1] = j-1;
			return p; 
		}else if( tmp > target ) j = mid-1;
		else i = mid+1;
    }
    p[0]=p[1]=-1;
    return p;
}

int main()
{
	int nums[6] = {5,7,7,8,8,10};
	int numsSize = 6;
	int returnSize,target;
	int *p;
	target = 10;
	p = searchRange(nums,numsSize,target,&returnSize);
	for( int i = 0; i < returnSize; i++ ){
		printf("%d ",p[i]);
	}
}


