/*
55. Jump Game
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.
*/

#include<stdio.h>

bool canJump(int* nums, int numsSize) {
	if( numsSize <= 1 ) return true;
	int nextjump;	//下一次跳跃点
	int jumpsize;	//本次的跳跃范围
	bool res = true;
	for( int i = 0; i < numsSize;  ){
		jumpsize = i + nums[i];	//计算本次的跳跃范围 
		if( jumpsize >= numsSize-1 ){	//到达终点 
			break;
		}
		nextjump = i;
		for( int j = i+1; j <= jumpsize; j++ ){	//选择下一次能到达更远的点 
			if( nums[j]+j > nextjump+nums[nextjump] ){
				nextjump = j;
			}
		}
		if( i == nextjump ){	//原地不动 
			res = false;
			break;
		}
		i = nextjump;
	}    
	return res;
}

int main()
{
	int nums[4] = {2,5,0,0};
	int numsSize = 4;
	bool res = canJump(nums,numsSize);
	if(res) printf("能");
	else printf("不能");
}
