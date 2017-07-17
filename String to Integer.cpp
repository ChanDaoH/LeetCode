#include<stdio.h>
#define INT_MAX 2147483647
#define INT_MIN -2147483648


int myAtoi(char* str) {
    int i;
    int ntag = 0;   //标明数字开始
    int result = 0;
    int mtag = 0;   //标明是否有符号
    char ch = '+';
    for ( i = 0; str[i] != '\0'; i++ ){
        if ( ntag  ){
            if (str[i] >= '0' && str[i] <= '9'){    //数字字符
                if (result >= INT_MAX/10){   //判断是否溢出
                    if (ch == '+' && (str[i] >= '8'||(result/1000000000)>0)){
                        return INT_MAX;
                    }else if (ch == '-' && (str[i] > '8'||(result/1000000000)>0)){
                        return INT_MIN;
                    }
                        
                }
                result = result * 10 + (str[i] - '0');
            }else{  //在读取数字的字符过程中读到非数字字符
                break;
            }
        }else{
            if (str[i] >= '0' && str[i] <= '9'){    //初次读取到数字字符
                result = str[i] - '0';
                ntag = 1;   //设置标志
            }else if (str[i] == '-' || str[i] == '+'){    //读取到符号
                if ( !mtag ){   //尚未读取到符号
                    mtag = 1;
                     ntag = 1;   //接下来应为数字字符
                    ch = str[i];
                }else{  //已经读取过符号
                    return 0;
                }
            }else if (str[i] != ' '){	//读取到非法字符 
				return 0;
            }
        }
    }
    if (!ntag) return 0;	//为读取过数字 
    if (ch == '+') return result;
    else return -1*result;

}

int main()
{
	int res;
	res = myAtoi("    010");
	printf("%d",res);
} 
