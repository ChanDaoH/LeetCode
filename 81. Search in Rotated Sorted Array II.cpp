/*
81. Search in Rotated Sorted Array II
*/


#include<stdio.h>

int find(int* nums, int numsSize, int target,int l, int r);

bool search(int* nums, int numsSize, int target){
	int l = 0,r = numsSize - 1;
	int res = find(nums,numsSize,target,l,r);
	return res>=0;
}

int find(int* nums, int numsSize, int target, int l, int r){
	if( r < l || l >= numsSize ){
		return -1;
	}
	int idx = -1;
	if( nums[l] < nums[r] ){
		int left = l,right = r,mid = 0;
		while( left <= right ){
			mid = (left+right)>>1;
			if( nums[mid] == target ){
				idx = mid;
				break;
			} 
			else if( nums[mid] < target ) left = mid + 1;
			else right = mid - 1;
		}
	}else{
		int mid = (l+r)>>1;
		if( nums[mid] == target ){
			idx = mid;
		}else{
			idx = find(nums,numsSize,target,l,mid-1);
			idx = idx==-1?find(nums,numsSize,target,mid+1,r):idx;
		}	
	}
	return idx;
}

int main()
{
	int nums[1] = {1};
	int numsSize = 1;
	bool res = search(nums,numsSize,1);
	if(res){
		printf("找到了");
	}else{
		printf("没找到");
	}
}
