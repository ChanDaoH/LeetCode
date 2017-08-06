/*
17. Letter Combinations of a Phone Number
*/



#include<stdio.h>
#include<stdlib.h>
void dfs(char* digits, int start, char** letters, char *sub, int count, int *size, char **res);
char** letterCombinations(char* digits, int* returnSize) {
    char **res,*sub,**letters;
    int start,count,size;
    start = count = size = 0;
    sub = (char*)malloc(sizeof(char)*100);
    res = (char**)malloc(sizeof(char*)*1000);
    
    letters = (char**)malloc(sizeof(char*)*10);
    for( int i = 0; i < 10; i++ ){
		*(letters + i) = (char*)malloc(sizeof(char)*5);
    }
    letters[0] = " ";letters[1] = "";letters[2]="abc";letters[3]="def";
    letters[4] = "ghi"; letters[5]="jkl";letters[6]="mno";letters[7]="pqrs";
    letters[8]="tuv"; letters[9] = "wxyz";
    
    if( digits[0] == '\0' ){
        *returnSize = 0;
        return NULL;
    } 
    
    dfs(digits,start,letters,sub,count,&size,res);
    *returnSize = size;
    return res;
    
}

void dfs(char* digits, int start, char** letters, char *sub, int count, int *size, char **res)
{
	int i,num;
	if( digits[start] == '\0' ){
		int k = *size;
		*(res + k) = (char*)malloc(sizeof(char)*(count+1));
		for( i = 0; i < count; i++ ){
			res[k][i] = sub[i];
		}
		res[k][i] = '\0';
		(*size)++;
		return;
	}
	num = digits[start] - '0';
	bool tag = true; //标志是否继续进行 
	for( i = 0; i < 4; i++ ){
		if( letters[num][i] ){
			tag = false;  //进入过子树,则不再进入下一层  
			sub[count++] = letters[num][i];
			dfs(digits,start+1,letters,sub,count,size,res);
			count--;
		}else{  
			if( tag ){  //未进入过子树则进入下一层 如 123 需要访问23 
				dfs(digits,start+1,letters,sub,count,size,res);
			}
			break;
		}
	}
	
}


int main()
{
	char *digits = "2034";
	int size;
	char **res;
	res = letterCombinations(digits,&size);
	for( int i = 0; i < size; i++ ){
		for( int j = 0; res[i][j] != '\0'; j++ ){
			printf("%c",res[i][j]);
		}
		printf("\n");
	}
}

