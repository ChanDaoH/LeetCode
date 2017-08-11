/*
95. Unique Binary Search Trees II
*/

#include<stdio.h>
#include<stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
struct TreeNode** helper(int start,int end,int *size);
struct TreeNode** generateTrees(int n, int* returnSize) {
    int size = 0;
    if(n==0){
        *returnSize = 0;
        return NULL;
    }
    struct TreeNode** res = helper(1,n,&size);
    *returnSize = size;
    return res;
}

struct TreeNode** helper(int start,int end,int *size){
	struct TreeNode **list = NULL;
	if (start == end){
		list = (struct TreeNode**)malloc(sizeof(struct TreeNode*));
		list[0] = (struct TreeNode*)malloc(sizeof(struct TreeNode));
		list[0]->val = start;
		list[0]->left = list[0]->right = NULL;
		(*size)++;
		return list;
	}
	if( start > end ){ /*返回空树*/
		list = (struct TreeNode**)malloc(sizeof(struct TreeNode*));
		list[0] = NULL;
		(*size)++;
		return list;
	}
	list = (struct TreeNode**)malloc(sizeof(struct TreeNode*)*(100));
	for( int i = start; i <= end; i++ ){
		struct TreeNode **left, **right;
		int leftsize,rightsize;
		leftsize = rightsize = 0;
		left = helper(start,i-1,&leftsize);  //左子树的集合 
		right = helper(i+1,end,&rightsize);  //右子树的集合 
		
		
		int s = *size;
		for( int l = 0; l < leftsize; l++ ){
			for( int r = 0; r < rightsize; r++ ){
				list[s] = (struct TreeNode*)malloc(sizeof(struct TreeNode));
				list[s]->val = i;   //当前子树的根节点为i 
				list[s]->left = left[l];  //左分支 
				list[s]->right = right[r];  //右分支 
				s++;
			}
		}
		*size = s;
	}
	return list;
}

int main()
{
	
}







