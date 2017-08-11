/*
94. Binary Tree Inorder Traversal
*/

#include<stdio.h>
#include<stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
 };

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    if ( root == NULL ){
		*returnSize = 0;
		return NULL;
    } 
    int *res = (int*)malloc(sizeof(int)*100);
    struct TreeNode *p,*tmp;
    struct TreeNode **Stack = (struct TreeNode**)malloc(sizeof(struct TreeNode*)*10);
	int top = -1;
    int size = 0;
    p = root;
    
    while( p != NULL || top != -1 ){
		//Stack[++top] = p;
		while( p != NULL ){
			Stack[++top] = p;
			p = p->left;
		}
		tmp = Stack[top--];
		res[size++] = tmp->val;
		p = tmp->right;
    }
    
    *returnSize = size;
    return res;
}

int main()
{
	
}
