/*
75. Sort Colors
*/

#include<stdio.h>
void sortColors(int* nums, int numsSize) {
	int color[3] = {0};
	int tmp;
	int size = 0;
	for( int i = 0; i < numsSize; i++ ){
		color[nums[i]]++;
	}	    
	for( int i = 0; i < 3; i++ ){
		tmp = color[i];
		for( int j = 0; j < tmp; j++ ){
			nums[size++] = i;
		}
	}
}
