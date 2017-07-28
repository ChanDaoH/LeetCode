#include<stdio.h>

int trap(int* height, int heightSize) {
	int i,j,k; //Ë«Ö¸Õë
	int tmp,sum;
	i = j = 0;
	tmp = 1;
	sum = 0;
	if( heightSize <= 2 ) return 0;
	for( j = 1; j < heightSize; j++ ){
		if( height[j] >= height[tmp] ) tmp = j;
		if( height[j] < height[i] ) continue;
		else{
			for( k = i; k<j;k++ ){
				sum += height[i]-height[k];
			}
			i = j;
			tmp++;
		}
	}    
	j--;
	if( height[j] < height[i] ){
		tmp = heightSize-1;
		for( k = heightSize-2; k > i; k-- ){
			if( height[k] < height[tmp] ){
				sum += height[tmp] - height[k];
			}else{
				tmp = k;
			}
		}
	}
	return sum;
}

int main()
{
	int height[12] = {0,1,0,2,1,0,1,3,2,1,2,1};
	int heightSize = 12;
	int res = trap(height,heightSize);
	printf("%d",res);
}
