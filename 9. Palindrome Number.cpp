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
	int hx,lx;	//���λ�����λ 
	int i=1;	//���λȨֵ 
	int len;	//��¼x��λ�� 
	int tmp;
	len = 0;
	if ( x < 0 ) return false;	//�������ǻ��� 
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
		if (hx != lx){	//���ǻ��� 
			return false;
		}
		x = (x - hx*i - lx) / 10;	//ʣ�µ��ַ� 
		if ( x == 0 ){
			return true; 
		} 
		len = len - 2;	//λ��-2 
		i = i / 100;	//Ȩֵ��100 
	}
	return true;
	
}
