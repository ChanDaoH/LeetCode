#include<stdio.h>

int removeElement(int* nums, int numsSize, int val) {
    int i,j;

    j = -1;
    i = 0;
    while( i < numsSize ){
		if( nums[i] == val ){
			i++;
		}else{
			nums[++j] = nums[i++];
		}
    }
    return j+1;
}

int main()
{
	int nums[4] = {3,2,2,3};
	int res = removeElement(nums,4,3);
	for( int i = 0; i < res; i++ ){
		printf("%d",nums[i]);
	}
}
