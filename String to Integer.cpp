#include<stdio.h>
#define INT_MAX 2147483647
#define INT_MIN -2147483648


int myAtoi(char* str) {
    int i;
    int ntag = 0;   //�������ֿ�ʼ
    int result = 0;
    int mtag = 0;   //�����Ƿ��з���
    char ch = '+';
    for ( i = 0; str[i] != '\0'; i++ ){
        if ( ntag  ){
            if (str[i] >= '0' && str[i] <= '9'){    //�����ַ�
                if (result >= INT_MAX/10){   //�ж��Ƿ����
                    if (ch == '+' && (str[i] >= '8'||(result/1000000000)>0)){
                        return INT_MAX;
                    }else if (ch == '-' && (str[i] > '8'||(result/1000000000)>0)){
                        return INT_MIN;
                    }
                        
                }
                result = result * 10 + (str[i] - '0');
            }else{  //�ڶ�ȡ���ֵ��ַ������ж����������ַ�
                break;
            }
        }else{
            if (str[i] >= '0' && str[i] <= '9'){    //���ζ�ȡ�������ַ�
                result = str[i] - '0';
                ntag = 1;   //���ñ�־
            }else if (str[i] == '-' || str[i] == '+'){    //��ȡ������
                if ( !mtag ){   //��δ��ȡ������
                    mtag = 1;
                     ntag = 1;   //������ӦΪ�����ַ�
                    ch = str[i];
                }else{  //�Ѿ���ȡ������
                    return 0;
                }
            }else if (str[i] != ' '){	//��ȡ���Ƿ��ַ� 
				return 0;
            }
        }
    }
    if (!ntag) return 0;	//Ϊ��ȡ������ 
    if (ch == '+') return result;
    else return -1*result;

}

int main()
{
	int res;
	res = myAtoi("    010");
	printf("%d",res);
} 
