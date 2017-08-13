/*
101. Symmetric Tree
*/

#include<stdio.h>
#include<stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool helper(struct TreeNode *left, struct TreeNode *right);
bool isSymmetric(struct TreeNode* root) {
    if(root != NULL){
		return helper(root->left,root->right);
    }
    return true;
}

bool helper(struct TreeNode *left, struct TreeNode *right){
	bool tagl,tagr;
	if( left != NULL && right != NULL ){
		if( left->val != right->val ){
			return false;
		}else{
			tagl = helper(left->left,right->right);
			if(!tagl) return false;
			else return helper(left->right,right->left);
		}
	}else if( left != NULL || right != NULL ){
		return false;
	}else{
		return true;
	}
}

int main()
{
	
}
