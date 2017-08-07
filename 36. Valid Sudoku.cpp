/*
36. Valid Sudoku
*/


#include<stdio.h>
#include<stdlib.h>
bool helper(int* nums, char ch);
bool isValidSudoku(char** board, int boardRowSize, int boardColSize) {
    int i,j,k;
    int nums[10] = {0};
    if( boardRowSize != 9 || boardColSize != 9 ) return false;
    //row
    for( i = 0; i < 9; i++ ){
		for( k = 0; k < 10; k++ ){
			nums[k] = 0;
		}
		for( j = 0; j < 9; j++ ){
			if(!helper(nums,board[i][j])) return false;
		}
    }
    //col
    for( j = 0; j < 9; j++ ){
		for( k = 0; k < 10; k++ ){
			nums[k] = 0;
		}
		for( i = 0; i < 9; i++ ){
			if(!helper(nums,board[i][j])) return false;
		}
    }
    //small board
    for( i = 0; i < 9; i+=3 ){
		for( j = 0; j < 9; j+=3 ){
			for( k = 0; k < 10; k++ ){
				nums[k] = 0;
			}
			for( k = 0; k < 9; k++ ){
				if(!helper(nums,board[i+k/3][j+k%3])) return false;
			}
		}
    }
    return true;
}

bool helper(int* nums, char ch){
	if( ch == '.' ){
		return true;
	}
	int x = ch - '0';
	if( x<1 || x>9 || nums[x] == 1 ) return false;
	nums[x] = 1;
	return true;
}

int main()
{
	
}
