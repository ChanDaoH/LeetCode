/*
5. Longest Palindromic Substring

Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example:

Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.
Example:

Input: "cbbd"

Output: "bb"
*/

#include<stdio.h>
#include<stdlib.h>
int expandAroundCenter(char *s, int left, int right);

char* longestPalindrome(char* s) {
	int start,end;
	int len1,len2,len;
	int i;
	start = end = 0;
	for( i = 0; s[i] != '\0'; i++ ){
		len1 = expandAroundCenter(s,i,i+1);
		len2 = expandAroundCenter(s,i,i);
		len = len1>len2?len1:len2;
		if( len > (end-start) ){
			end = i + len/2;
			start = i - (len-1)/2;
		}
	}    
	char *p = (char*)malloc(sizeof(char)*(end-start+2));
	for( i = start; i<=end; i++ ){
		p[i-start] = s[i];
	}
	p[end-start+1] = '\0';
	return p;
}

int expandAroundCenter(char *s, int left, int right){
	int L,R;
	L = left;
	R = right;
	while( L >=0 && s[R] != '\0' && s[L]==s[R] ){
		L--;
		R++;
	}
	return R-L-1;
}



int main()
{
	char *s = "babad";
	char *p;
	p = longestPalindrome(s);
	printf("%s",p);
}


















