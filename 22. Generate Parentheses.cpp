/*
22. Generate Parentheses
*/

#include<stdio.h>
#include<stdlib.h>
void dfs(int *size, int count, char* subset, char**res, int left, int right, int n );
char** generateParenthesis(int n, int* returnSize) {
	char **res, *subset;
	int size, count, left, right;
	
	if (n == 0) {
		*returnSize = 0;
		return NULL;
	}
	size = count = left = right = 0;

	subset = (char*)malloc(sizeof(char)*(2*n));
	
	res = (char**)malloc(sizeof(char*)*(10000));
	
	for (int i = 0; i < 10000; i++) {
		*(res + i) = (char*)malloc(sizeof(char)*(2*n+1));
	}
	
	dfs( &size, count, subset, res, left,right,n);
	*returnSize = size;
	return res;

}

void dfs(int *size, int count, char* subset, char**res, int left, int right, int n )
{
	if( right == n ){
		int k = *size;
		int i = 0;
		for( i = 0; i < count; i++ ){
			res[k][i] = subset[i];
		}
		res[k][i] = '\0';
		(*size)++;
	}else if( left == n ){
		subset[count++] = ')';
		dfs(size,count,subset,res,left,right+1,n);
	}else{
		if( left > right ){
			subset[count++] = ')';
			dfs(size,count,subset,res,left,right+1,n);
			count--;
		}
		subset[count++] = '(';
		dfs(size,count,subset,res,left+1,right,n);
		count--;
	}
}

int main()
{
	int n = 3;
	int size;
	char **res;
	res = generateParenthesis(n, &size);
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < 2 * n; j++) {
			printf("%c", res[i][j]);
		}
		printf("\n");
	}
}





