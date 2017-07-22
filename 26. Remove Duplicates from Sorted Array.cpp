#include<stdio.h>
int removeDuplicates(int* nums, int numsSize) {
    int i,j;	//Ë«Ö¸Õë
    if(numsSize == 0){
		return 0;
    }
	i = j = 0;
	i++;
	while( i < numsSize ){
		if( nums[i] != nums[i-1] ){
			nums[++j] = nums[i++];
		}
		else
			i++;
	}
	return j+1;
}

int main()
{
	int a[3] = {1,1,2};
	int res = removeDuplicates(a,3);
	for( int i = 0; i < res; i++ ){
		printf("%d ",a[i]);
	}
}
