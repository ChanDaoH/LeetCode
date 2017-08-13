/*
103. Binary Tree Zigzag Level Order Traversal
*/


#include<stdio.h>
#include<vector>
#include<iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
	vector<vector<int> > res;
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        buildVector(root,0);
        return res;
    }
    void buildVector(struct TreeNode *root, int depth){
		if( root == NULL ) return;
		if( res.size() == depth ){
			res.push_back(vector<int>());
		}
		if( depth%2 == 0 ){
			res[depth].push_back(root->val);
		}else{
			res[depth].insert(res[depth].begin(),root->val);
		}
		buildVector(root->left,depth+1);
		buildVector(root->right,depth+1);
    }
};

int main()
{
	
}
