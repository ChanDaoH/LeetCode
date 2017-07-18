#include<stdio.h>
#include<stdlib.h>
bool isPalindrome(int x);


int main()
{
	bool x;
	printf("\n");
	x = isPalindrome(1000000001);
}

bool isPalindrome(int x) {
	int hx,lx;	//最高位、最低位 
	int i=1;	//最高位权值 
	int len;	//记录x的位数 
	int tmp;
	len = 0;
	if ( x < 0 ) return false;	//负数不是回文 
	tmp = x;
	while ( tmp!= 0 ){
		tmp = tmp / 10;
		len++;
	}   
	for ( int k = 0; k < len - 1; k++ ){
		i = i * 10;
	}
	while( len > 1 ){
		hx = x/i;	
		lx = x - (x/10)*10;
		if (hx != lx){	//不是回文 
			return false;
		}
		x = (x - hx*i - lx) / 10;	//剩下的字符 
		if ( x == 0 ){
			return true; 
		} 
		len = len - 2;	//位数-2 
		i = i / 100;	//权值除100 
	}
	return true;
	
}
