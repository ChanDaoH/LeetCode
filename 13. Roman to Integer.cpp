/*
13. Roman to Integer
*/

#include<stdio.h>

int find(char ch);
int romanToInt(char* s) {
	int m,n;
    int result = 0;
    for( int i = 0; s[i] != '\0'; i++ ){
		if( i > 0 ){
			n = find(s[i]);
			result += n;
			if( m < n ){
				result -= 2*m;
			}
		}else{
			n = find(s[i]);
			result += n;
		}
		m = n;
    }
    return result;
}

int find(char ch){
	switch(ch) {
      case 'I':return 1;
      case 'V':return 5;
      case 'X':return 10;
      case 'L':return 50;
      case 'C':return 100;
      case 'D':return 500;
      case 'M':return 1000;
    }
    return 0;

}

int main(){
	char *s = "CXCIX";
	int res = romanToInt(s);
	printf("%d",res);
}


