/*
79. Word Search
*/


#include<stdio.h>
#include<stdlib.h>
bool search(char**board, int boardRowSize, int boardColSize,char* word, int pos, int len, int x, int y, int**mask);

bool exist(char** board, int boardRowSize, int boardColSize, char* word) {
    if( boardRowSize < 1 || boardColSize < 1 ){
		return false;
    }
    int len = 0;
    int** mask;
    mask = (int**)malloc(sizeof(int*)*boardRowSize);
    for( int k = 0; k < boardRowSize; k++ ){
		*(mask+k) = (int*)malloc(sizeof(int)*boardColSize);
    }
    for( int i = 0; i < boardRowSize; i++ ){
		for( int j = 0; j < boardColSize; j++ ){
			mask[i][j] = 0;
		}
    }
    
    for( int k = 0; word[k] != '\0'; k++ ){
		len++;
    }
    if ( len < 1 ){
		return true;
    }
    for( int i = 0; i < boardRowSize; i++ ){
		for( int j = 0; j < boardColSize; j++ ){
			if( board[i][j] == word[0] && search(board,boardRowSize,boardColSize,word,0,len,i,j,mask ) ){
				return true;
			}
		}
    }
    return false;
}


bool search(char**board, int boardRowSize, int boardColSize,char* word, int pos,int len,int x, int y,int** mask)
{
	if( board[x][y] == word[pos] && mask[x][y] == 0 ){
		pos++;
		if( pos == len ) return true;	//查找串全部找到 
	}else{
		return false;
	}
	//寻找串中的下一个字符 
	mask[x][y] = 1;
	if( y+1 < boardColSize && search(board,boardRowSize,boardColSize,word,pos,len,x,y+1,mask )){  //左边 
		return true;
	}
	
	if( y-1 >= 0 && search(board,boardRowSize,boardColSize,word,pos,len,x,y-1,mask)){	//右边 
		return true;
	}
	
	if( x-1 >= 0 && search(board,boardRowSize,boardColSize,word,pos,len,x-1,y,mask)){	//上边
		return true; 
	}	
	
	if( x+1 < boardRowSize && search(board,boardRowSize,boardColSize,word,pos,len,x+1,y,mask)){ //下边
		return true; 
	}
	mask[x][y] = 0;
	return false;
}

int main()
{
	char **board;
	char word[7] = "ABCB";
	bool result;
	int row,col;
	row = 3 ; col = 4;
	board = (char**)malloc(sizeof(char*)*row);
	for( int i = 0; i < row; i++ ){
		*(board + i) = (char*)malloc(sizeof(char)*col);
	}
	board[0][0] = 'A';board[0][1] = 'B';board[0][2] = 'C';board[0][3] = 'E';
	board[1][0] = 'S';board[1][1] = 'F';board[1][2] = 'C';board[1][3] = 'S';
	board[2][0] = 'A';board[2][1] = 'D';board[2][2] = 'E';board[2][3] = 'E';
	
	result = exist(board,row,col,word);
	if(result){
		printf("找到了");
	}else{
		printf("没找到");
	}
}







