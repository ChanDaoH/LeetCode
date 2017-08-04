/*
80. Remove Duplicates from Sorted Array II
*/

#include<stdio.h>

int removeDuplicates(int* nums, int numsSize) {
	int j,size,dup;
	bool newletter = true;
	size = 0;
	 j = 0;
	for( int i = 0; i < numsSize; i++ ){
		dup = 0;size++;
		nums[j++] = nums[i];
		while( i< numsSize-1 && nums[i] == nums[i+1] ){
			dup++; 
			if( dup < 2 ){
				size++;
				nums[j++] = nums[i];
			} 
			i++;
		}
	}    
	return size;
}

int main()
{
	int nums[4] = {1,1,1,2};
	int numsSize = 4;
	int size;
	size = removeDuplicates(nums,numsSize);
	for( int i = 0; i < size; i++ ){
		printf("%d ",nums[i]);
	}
}
