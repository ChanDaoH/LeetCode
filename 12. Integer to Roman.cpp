/*
12. Integer to Roman
*/
#include<stdio.h>
#include<stdlib.h>

char* intToRoman(int num) {
	char *res; 
    char roman[7] = {'I','V','X','L','C','D','M'};
    int  value[7] = { 1, 5,  10, 50, 100,500,1000 };
    int i,j,k;
    j = 0;
    res = (char*)malloc(sizeof(char)*22);
    for( i = 6; i >=0 ; i-=2 ){
		int x = num/value[i];
		if( x < 4 ){
			for( k = 0; k < x; k++ ){
				res[j++] = roman[i];
			}
		}else if( x == 4 ){
			res[j++] = roman[i];
			res[j++] = roman[i+1];
		}else if( x < 9 ){
			res[j++] = roman[i+1];
			for( k = x-5; k > 0; k-- ){
				res[j++] = roman[i];
			}
		}else if( x == 9 ){
			res[j++] = roman[i];
			res[j++] = roman[i+2];
		}
		num = num - x*value[i];
    }
    res[j] = '\0';
    return res;
}


int main()
{
	int num = 6;
	char *res = intToRoman(num);
	for( int i = 0; res[i] != '\0'; i++ ){
		printf("%c",res[i]);
	} 
}
