#include<stdio.h>
#include<stdlib.h>

int maxArea(int* height, int heightSize);

int main()
{
	
}


int maxArea(int* height, int heightSize) {
    int left,right;	//���������˵�
	int res;	//���
	int a,b;	//��͸� 
	int tmp;
	left = res = 0;
	a = right = heightSize-1;
	while(a>0){
		if(height[left] < height[right]){	//���ǽ϶̱� 
			b = height[left];
			left++;
		}else{
			b = height[right];
			right--;
		}
		tmp = a*b;
		res = res>tmp?res:tmp;
		a--;	//���ȼ�һ 
	} 
	return res;
}









