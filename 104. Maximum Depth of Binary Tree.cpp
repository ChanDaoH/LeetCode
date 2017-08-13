/*
104. Maximum Depth of Binary Tree
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
	int maxdepth;
    int maxDepth(TreeNode* root) {
        maxdepth = 0;
        depthSolver(root,1);
        return maxdepth;
    }
    void depthSolver(TreeNode* root, int depth){
		if(root == NULL){
			return;
		}
		if( depth > maxdepth ){
			maxdepth = depth;
		}
		depthSolver(root->right,depth+1);
		depthSolver(root->left,depth+1);
    }
};

int main()
{
	
}
