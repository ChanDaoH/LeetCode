/*
67. Add Binary
*/
#include<stdio.h>
#include<stdlib.h>
char* addBinary(char* a, char* b) {
    int bit = 0;
    int lena,lenb,lenr,i,j,k;
    int s,t;
    lena = lenb = 0;
    for( i = 0; a[i] != '\0'; i++ ){
		lena++;
    }
    if( lena == 0 ) return b;
    for( j = 0; b[j] != '\0'; j++ ){
		lenb++;
    }
    if( lenb ==0 ) return a;
    lenr = lena>lenb?(lena+1):(lenb+1); //包括\0 
    char *res = (char*)malloc(sizeof(char)*(lenr+1)); //包括进位 
    k = lenr-1;
    for(j--,i--;i>=0 && j>=0;i--,j--){
		s = a[i]-'0'; t = b[j]-'0';
		res[k--] = (s^t^bit)+'0';
		bit = ((s&t) + (s&bit) + (t&bit))>0?1:0;
    }
    if( i >= 0 ){
		while( i>=0 ){
			s = a[i]-'0'; 
			res[k--] = (s^bit)+'0';
			bit = s&bit;
			i--;
		}
    }
    if( j >= 0 ){
		while( j>=0 ){
			s = b[j]-'0'; 
			res[k--] = (s^bit)+'0';
			bit = s&bit;
			j--;
		}
    }
    if( bit ){
		res[k] = '1';
		res[lenr] = '\0';
		return res;
    }else{
		res[lenr] = '\0';
		return &res[1];
    }
}

int main()
{
	char *a = "1111";
	char *b = "1111";
	char *c = addBinary(a,b);
	for( int i = 0; c[i] != '\0'; i++ ){
		printf("%c",c[i]);
	}
}
