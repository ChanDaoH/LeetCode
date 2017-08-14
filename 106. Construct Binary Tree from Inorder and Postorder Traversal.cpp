/*
106. Construct Binary Tree from Inorder and Postorder Traversal
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
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		return construct(inorder, postorder, postorder.size() - 1, 0, inorder.size() - 1);
	}
	TreeNode* construct(vector<int>& inorder, vector<int>& postorder, int postStart, int inStart, int inEnd) {
		if (inStart > inEnd) {
			return NULL;
		}
		TreeNode* root = new TreeNode(postorder[postStart]);
		int inIndex = 0;
		for (int i = inStart; i <= inEnd; i++) {
			if (inorder[i] == postorder[postStart]) {
				inIndex = i;
				break;
			}
		}
		root->right = construct(inorder, postorder, postStart - 1, inIndex + 1, inEnd);
		root->left = construct(inorder, postorder, postStart - inEnd + inIndex - 1, inStart, inIndex - 1);
		return root;
	}
};

int main()
{
	int a[1] = { -1 };
	int b[1] = { -1 };
	vector<int> inorder;
	inorder.push_back(-1);
	vector<int> postorder;
	postorder.push_back(-1);
	TreeNode *res;
	Solution s;
	res = s.buildTree(inorder, postorder);
}
