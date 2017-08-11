/*
52. N-Queens II
*/


#include<stdio.h>
#include<stdlib.h>
void helper(int n,int row,int *size,int *col,int **chessBoard);
int totalNQueens(int n) {
	int *col;  //��¼ÿһ��queen�������� 
	col = (int*)malloc(sizeof(int)*n);  
	int row = 0;
	int count = 0; //���㵽�ڼ���queen 
	int size = 0;  //�ܴ���
	int **chessBoard = (int**)malloc(sizeof(int*)*n);
	for( int i = 0; i < n; i++ ){
		col[i] = 0;
		*(chessBoard+i) = (int*)malloc(sizeof(int)*n); 
	}
	for( int i = 0; i < n; i++ ){
		for( int j = 0; j < n; j++ ){
			chessBoard[i][j] = 0;
		}
	}
	helper(n,row,&size,col,chessBoard);
	return size;
	
}

void helper(int n,int row,int *size,int *col,int **chessBoard)
{
	if(row >= n){
		(*size)++;
		return;
	}
	for( int i = 0; i < n; i++ ){
		if( !col[i] ){
			/*�ж�45���*/
			int x = row; int y = i;
			if( x > y ){
				x = row-i; y = 0;
			}else{
				x = 0; y = i-row;
			}
			int u,v;
			bool canAtack = false;
			for( u = x,v=y;u<n&&v<n;u++,v++){
				if(chessBoard[u][v]){
					canAtack = true;
					break;
				}
			}
			if(canAtack) continue;
			/*�ж�135�Ƚ�*/
			x = row;y=i;
			while(x<n-1&&y>0){
				x++;y--;
			}
			for( u = x,v=y;u>=0&&v<n;u--,v++){
				if(chessBoard[u][v]){
					canAtack = true;
					break;
				}
			}
			if(canAtack) continue;
			/*dfs*/
			col[i] = 1;
			chessBoard[row][i] = 1;
			helper(n,row+1,size,col,chessBoard);
			col[i] = 0;
			chessBoard[row][i] = 0;
		}
	}
}

int main()
{
	int res = totalNQueens(9);
	printf("%d",res);
}





