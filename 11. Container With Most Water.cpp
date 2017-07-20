#include<stdio.h>
#include<stdlib.h>

int maxArea(int* height, int heightSize);

int main()
{
	
}


int maxArea(int* height, int heightSize) {
    int left,right;	//左右两个端点
	int res;	//结果
	int a,b;	//宽和高 
	int tmp;
	left = res = 0;
	a = right = heightSize-1;
	while(a>0){
		if(height[left] < height[right]){	//高是较短边 
			b = height[left];
			left++;
		}else{
			b = height[right];
			right--;
		}
		tmp = a*b;
		res = res>tmp?res:tmp;
		a--;	//长度减一 
	} 
	return res;
}









