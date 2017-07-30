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
	int nextjump;	//��һ����Ծ��
	int jumpsize;	//���ε���Ծ��Χ
	bool res = true;
	for( int i = 0; i < numsSize;  ){
		jumpsize = i + nums[i];	//���㱾�ε���Ծ��Χ 
		if( jumpsize >= numsSize-1 ){	//�����յ� 
			break;
		}
		nextjump = i;
		for( int j = i+1; j <= jumpsize; j++ ){	//ѡ����һ���ܵ����Զ�ĵ� 
			if( nums[j]+j > nextjump+nums[nextjump] ){
				nextjump = j;
			}
		}
		if( i == nextjump ){	//ԭ�ز��� 
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
	if(res) printf("��");
	else printf("����");
}
