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
	for (i = 0; i < len1 + len2 + 2; i++) res[i] = '0'; //�������ȫ��0 
	k = len1 + len2 + 1; //�ӵ�λ���λ�ƶ� 
	res[k--] = '\0'; //�ַ���������� 
	c0 = 0; //��λ�����0 
	for (i = len1 - 1; i >= 0; i--) {
		p = k; 
		for (j = len2 - 1; j >= 0; j--) {
			sum = (num1[i] - '0')*(num2[j] - '0') + c0 + (res[p] - '0');
			c0 = sum / 10;
			res[p--] = '0' + sum % 10;
		}
		res[p--] = '0' + c0; //���һλ��λ 
		c0 = 0; //��λ��0 
		k--; //�߼�������� 
	}
	while (res[p+1] != '\0' && res[p] == '0') p++;
	return &(res[p]);
}

int main()
{
	char *res = multiply("0", "0");
	printf("%s", res);
}
