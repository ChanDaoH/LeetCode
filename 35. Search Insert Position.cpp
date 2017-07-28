/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 ¡ú 2
[1,3,5,6], 2 ¡ú 1
[1,3,5,6], 7 ¡ú 4
[1,3,5,6], 0 ¡ú 0
*/

#include<stdio.h>

int searchInsert(int* nums, int numsSize, int target) {
	int i = 0;
	int j = numsSize - 1;
	int tmp,mid;
	while( i <= j ){
		mid = (i+j)/2;
		tmp=nums[mid];
		if(tmp == target){
			return mid;
		}else if( tmp < target ){
			i = mid+1;
		}else{
			j = mid-1;
		}
	}   
	return i;
}
