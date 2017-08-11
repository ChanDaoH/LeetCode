/*
60. Permutation Sequence
*/


#include<stdio.h>
#include<stdlib.h>
char* getPermutation(int n, int k) {
	int psum = 1,num;
	int *s = (int*)malloc(sizeof(int) * 9);
	char *res = (char*)malloc(sizeof(char) * 10);
	int i;
	for (i = 1; i < n; i++) {
		psum *= i; //n-1个数的排列总数 
	}
	for (i = 0; i < 9; i++) s[i] = 0;
	k--;
	int idx = k / psum; //第idx组 即要放入结果集中的未访问集中的下标 
	int next = k%psum; //第idx组中的第next个排列 
	i = 0; num = n;
	bool first = true;
	while (idx != 0 || first) {
		first = false;
		for (int j = 0; j < n; j++) {
			if (!s[j]) {
				if (idx == 0) {
					res[i++] = '0' + j + 1;
					s[j] = 1;
					break;
				}
				else {
					idx--;
				}
			}
		}
		psum = psum / (--num);
		idx = next / psum;
		next = next%psum;
	}

	for (int j = 0; j < n; j++) {
		if (!s[j]) {
			res[i++] = '0' + j + 1;
		}
	}
	res[i] = '\0';
	return res;
}


int main()
{
	char *s = getPermutation(4,2);
	printf("%s",s);
}
