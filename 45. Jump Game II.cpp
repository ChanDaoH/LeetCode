/*
45. Jump Game II
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

Note:
You can assume that you can always reach the last index.
*/
#include<stdio.h>

int jump(int* nums, int numsSize) {
	if( numsSize <= 1 ) return 0;
	int i,j,tmp;
	int len,path;
	int tail = numsSize-1;
	i = path = 0;
	j = 1;
	len = 0;
	while( i < tail ){ //δ����ĩβ 
		path = i+nums[i];	//��������Ծ������Զ����� 
		tmp = i+1;			//Ĭ�����ǰ��һ�� 
		if( path >= tail ) return len+1;	//��Զ�������ڵ���ĩβ���꣬����+1������ 
		for( j = i+1; j <= path; j++ ){		//��һ�ε������ѡ���ܵ����Զ���������� 
			if( j+nums[j] > tmp+nums[tmp] ){	
				tmp = j;
			}
		}
		i = tmp;	//ǰ������һ������ 
		len++;		//����+1 
	}    
	return path;
}

int main()
{
	int nums[5] = {1,2,3,4,5};
	int numsSize = 5;
	int res = jump(nums,numsSize);
	printf("\n%d\n",res);
}


