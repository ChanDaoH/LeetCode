/*
105. Construct Binary Tree from Preorder and Inorder Traversal
*/


#include<stdio.h>
#include<vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		return construct(preorder, inorder, 0, 0, inorder.size() - 1);
	}
	TreeNode* construct(vector<int>& preorder, vector<int>& inorder, int idx, int left, int right) {
		if (left > right) return NULL;
		TreeNode *p = new TreeNode(preorder[idx]);
		int i;
		for (i = 0; i < inorder.size(); i++) {
			if (inorder[i] == preorder[idx]) {
				break;
			}
		}
		p->left = construct(preorder, inorder, idx+1, left, i - 1);
		p->right = construct(preorder, inorder, idx+i-left+1, i + 1, right);
		return p;
	}
};
int main()
{
	int a[4] = {3,2,1,4};
	int b[4] = {1,2,3,4};
	vector<int> preorder(a,a+4);
	vector<int> inorder(b,b+4);
	TreeNode* res;
	Solution c = new Solution();
	res = c.buildTree(preorder,inorder);
}
