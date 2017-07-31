/*
66. Plus One
Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.

You may assume the integer do not contain any leading zero, except the number 0 itself.

The digits are stored such that the most significant digit is at the head of the list.
*/

#include<stdio.h>
#include<stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int *res;
    int sum;
    bool flag;
    if( digitsSize < 1 ) return NULL;
    res = (int*)malloc(sizeof(int)*(digitsSize+1));
    flag = true;
    for( int i = digitsSize-1; i > -1; i-- ){
		if( flag ){
			if( digits[i] == 9 ){
				res[i+1] = 0;
			}
			else{
				res[i+1] = digits[i]+1;
				flag = false;
			}
		}else{
			res[i+1] = digits[i];
		}
    }
    if(flag){
		res[0] = 1;
		*returnSize = digitsSize+1;
    }else{
		res = res+1;
		*returnSize = digitsSize;
    }
    return res;
}

int main()
{
	int digits[1] = {0};
	int digitsSize = 1;
	int size;
	int *res;
	res = plusOne(digits,digitsSize,&size);
	for( int i = 0; i < size; i++ ){
		printf("%d",res[i]);
	}
}

