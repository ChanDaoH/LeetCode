/*
28. Implement strStr()
*/

#include<stdio.h>
#include<stdlib.h>

int strStr(char* haystack, char* needle) {
    int i,j,k;
    int lenh = 0,lenn = 0;
	for( i = 0; haystack[i] != '\0'; i++ ){
		lenh++;
	}
	for( i = 0; needle[i] != '\0'; i++ ){
		lenn++;
	}
	if( lenn == 0 ) return 0;
    for( i = 0; i < lenh; i++ ){
		
		for( j = 0; j < lenn; j++ ){
			if( haystack[i+j] != needle[j] ) break;
		}
		if( j == lenn ) return i;
    }
    return -1;
}

int main()
{
	char *s = "";
	char *t = "a";
	int res = strStr(s,t);
	printf("%d",res);
}
