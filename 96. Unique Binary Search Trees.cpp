/*
96. Unique Binary Search Trees
*/


#include<stdio.h>
#include<stdlib.h>

int numTrees(int n) {
	int *num;
	int sum=0;
	num = (int*)malloc(sizeof(int)*(n+1));
	num[1] = 1;
	num[0] = 1;
	for( int i = 2; i <= n; i++ ){
		sum = 0;
		for( int j = 1; j <= i; j++ ){
			int L = j-1; //��ߵĽڵ���� 
			int R = i-j; //�ұߵĽ����� 
			sum += num[L]*num[R]; //����������̬���� 
		}
		num[i] = sum;
	}    
	return num[n];
}

int main()
{
	printf("%d\n",numTrees(4));
}
