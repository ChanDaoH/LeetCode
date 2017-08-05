/*
20. Valid Parentheses
*/

#include<stdio.h>
#include<stdlib.h>

bool isValid(char* s) {
    char *stack;
    int top = -1;
    
    stack = (char*)malloc(sizeof(char)*100);
    
    for( int i = 0; s[i] != '\0'; i++ ){
		switch(s[i]){
			case '(' :
			case '{' :
			case '[' : stack[++top] = s[i]; break;
			case ')' :
				if( top >= 0 && stack[top] == '(' ){
					top--;
				}else{
					return false;
				}
				break;
			case '}' :
				if( top >= 0 && stack[top] == '{' ){
					top--;
				}else{
					return false;
				}
				break;
			case ']' : 
				if( top >= 0 && stack[top] == '[' ){
					top--;
				}else{
					return false;
				}
				break;
		}
    }
    if( top >= 0 ){
		return false;
    }
    return true;
}

int main()
{
	char *s = "()";
	bool res = isValid(s);
	if(res){
		printf("合法");
	}else{
		printf("不合法");
	}
}
