/*
43. Multiply Strings
*/

#include<stdio.h>
#include<stdlib.h>

char* multiply(char* num1, char* num2) {
	int len1 = 0, len2 = 0, len;
	int i, j, k, p;
	int sum, c0;
	for (i = 0; num1[i] != '\0'; i++) len1++;
	for (j = 0; num2[j] != '\0'; j++) len2++;
	char *res = (char*)malloc(sizeof(char)*(len1 + len2 + 2));
	for (i = 0; i < len1 + len2 + 2; i++) res[i] = '0'; //结果数组全置0 
	k = len1 + len2 + 1; //从低位向高位移动 
	res[k--] = '\0'; //字符串结束标记 
	c0 = 0; //进位标记置0 
	for (i = len1 - 1; i >= 0; i--) {
		p = k; 
		for (j = len2 - 1; j >= 0; j--) {
			sum = (num1[i] - '0')*(num2[j] - '0') + c0 + (res[p] - '0');
			c0 = sum / 10;
			res[p--] = '0' + sum % 10;
		}
		res[p--] = '0' + c0; //最后一位进位 
		c0 = 0; //进位置0 
		k--; //逻辑光标左移 
	}
	while (res[p+1] != '\0' && res[p] == '0') p++;
	return &(res[p]);
}

int main()
{
	char *res = multiply("0", "0");
	printf("%s", res);
}
