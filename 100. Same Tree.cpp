/*
100. Same Tree
*/


#include<stdio.h>
#include<stdlib.h>


struct TreeNode{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};


bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    bool ltag,rtag; //左子树，右子树是否相同
	
	if( p == NULL && q == NULL ){
		return true;
	}else if( p != NULL && q != NULL ){
		if( p->val != q->val ){
			return false;
		}
	}else{
		return false;
	}
	
	ltag = isSameTree( p->left,q->left );
	if( !ltag ) return false;
	else{
		rtag = isSameTree( p->right,q->right );
		return rtag;
	}
}

int main()
{
	
}
