/*
10. Regular Expression Matching
*/

#include<stdio.h>
#include<stdlib.h>

bool isMatch(char* s, char* p) {
	int **matchTable;
	int i, j;
	int lens = 0, lenp = 0;
	for (i = 0; s[i] != '\0'; i++) {
		lens++;
	}
	if (lens == 0) return true;
	for (j = 0; p[j] != '\0'; j++) {
		lenp++;
	}
	if (lenp == 0) return false;
	matchTable = (int**)malloc(sizeof(int*)*(lenp + 1));
	for (i = 0; i <= lenp; i++) {
		*(matchTable + i) = (int*)malloc(sizeof(int)*(lens + 1));
	}

	for (j = 0; j <= lens; j++) matchTable[0][j] = 0;
	for (i = 0; i <= lenp; i++) matchTable[i][0] = 0;
	
	matchTable[0][0] = 1;
	for (j = 0; j <= lens; j++) {
		for (i = 1; i <= lenp; i++) {
			if( p[i-1] == '.' ){
				if( j > 0 && matchTable[i-1][j-1] ){
					matchTable[i][j] = 1;
				}else{
					matchTable[i][j] = 0;
				}
			}
			else if( p[i-1] == '*' ){
				/*代表前面0个字符*/
				if( i > 1 && matchTable[i-2][j] == 1 ){
					matchTable[i][j] = 1;
				}else if( i > 1 && matchTable[i-1][j-1] == 1 && (p[i-2]==s[j-1]||p[i-2]=='.')){ /*1个字符*/
					matchTable[i][j] = 1;
				}else if( i > 1 ){ /*多个字符*/
					int k = j;
					if( p[i-2] == '.' ){
						if ( i <= lens && matchTable[i-2][i-2] == 1 ){
							matchTable[i][j] = 1;
						}else{
							matchTable[i][j] = 0;
						}
					}else{
						while( k > 0 && s[k-1] == p[i-2] ) k--;
						k++;
						if( matchTable[i-2][k] == 1 ){
							matchTable[i][j] = 1;
						}else{
							matchTable[i][j] = 0;
						}
					}
				}else{
					matchTable[i][j] = 0;
				}
			}
			else if(j > 0 && matchTable[i-1][j-1] == 1 && p[i-1] == s[i-1] ){
				matchTable[i][j] = 1;
			}else{
				matchTable[i][j] = 0;
			}
		}
	}
	return matchTable[lenp][lens] == 1;
}

int main()
{
	char s[10] = "aa";
	char p[10] = "aa";
	bool res = isMatch(s,p);
	
	printf("%d\n",isMatch("aa","a"));
	printf("%d\n",isMatch("aa","aa"));
	printf("%d\n",isMatch("aaa","aa"));
	printf("%d\n",isMatch("aa","a*"));
	printf("%d\n",isMatch("aa",".*"));
	printf("%d\n",isMatch("ab",".*"));
	printf("%d\n",isMatch("aab","c*a*b"));
	printf("%d\n",isMatch("aaa","ab*a*c*a"));
	printf("%d\n",isMatch("aaa",".*"));
}
