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
		psum *= i; //n-1�������������� 
	}
	for (i = 0; i < 9; i++) s[i] = 0;
	k--;
	int idx = k / psum; //��idx�� ��Ҫ���������е�δ���ʼ��е��±� 
	int next = k%psum; //��idx���еĵ�next������ 
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
