/*
14. Longest Common Prefix
*/

#include<stdio.h>
#include<stdlib.h>
char* longestCommonPrefix(char** strs, int strsSize) {
    char *str, ch;
    bool isLast = false;
    int i = 0, j = 0; //j指向了最后一个相同元素的后一位 
    if( strsSize < 1 ) return NULL;
    for( j = 0; strs[0][j] != '\0'; j++ ){
		ch = strs[0][j];
		for( i = 1; i < strsSize; i++ ){
			if( strs[i][j] == '\0' || strs[i][j] != ch ){
				isLast = true;
				break;
			}
		}
		if( isLast ) break;
    }
    
	str = (char*)malloc(sizeof(char)*(j+1)); //申请j+1大小的空间,下标j存放\0 
    for( int k = 0; k < j; k++ ){
		str[k] = strs[0][k];
    }
    str[j] = '\0';
    
    return str;
}

int main()
{
	char **strs;
	strs = (char**)malloc(sizeof(char*)*2);
	strs[0] = "cba";
	strs[1] = "c";
	char *res = longestCommonPrefix(strs,2);
	for( int i = 0; res[i] != '\0'; i++ ){
		printf("%c",res[i]);
	}
}
