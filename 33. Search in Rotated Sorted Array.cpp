#include<stdio.h>

int bitSearch(int *nums,int min,int max,int target);

int search(int* nums, int numsSize, int target) {
    int min = 0;
    int max = numsSize -1;
    int res = bitSearch(nums,min,max,target);
    return res;
}

int bitSearch(int *nums,int min,int max,int target)
{
	int i,j;
	int mid,tmpmid,tmpmax,tmpmin;
	int resl,resr;
	i = min;
	j = max;
	resl=resr=-1;
	while(i <= j){
		mid = (i+j)/2;
		tmpmax = nums[max];
		tmpmid = nums[mid];
		tmpmin = nums[min];
		if(tmpmid == target) return mid;
		else if( tmpmax < tmpmin ){
			resl = bitSearch(nums,min,mid-1,target);
			resr = bitSearch(nums,mid+1,max,target);
			break;
		}else if(tmpmid < target) i = mid+1;
		else j = mid-1;
	}
	if(resl != -1) return resl;
	if(resr != -1) return resr;
	return -1;
}

int main()
{
	int nums[6] = {3,4,5,6,1,2};
	int numsSize = 6;
	int target = 2;
	int res = search(nums,numsSize,target);
	printf("%d",res);
}
