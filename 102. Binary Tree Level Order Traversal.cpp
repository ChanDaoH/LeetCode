/*
102. Binary Tree Level Order Traversal
*/

#include<stdio.h>
#include<vector>
#include<queue>
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
    vector<vector<int> > levelOrder(TreeNode* root) {
        vector<vector<int> > res;
        queue<int> layer;
        queue<struct TreeNode*> Q;
        struct TreeNode* p;
        int lay,curlay;
        if( root == NULL ){
			return res;
        }
        Q.push(root);
        layer.push(0);
        curlay = -1;
        while( !Q.empty() ){
			p = Q.front();
			lay = layer.front();
			Q.pop();
			layer.pop();
			if(curlay < lay){
				curlay = lay;
				res.push_back(vector<int>());
			}
			res[lay].push_back(p->val);
			if(p->left){
				Q.push(p->left);
				layer.push(lay+1); 
			}
			if(p->right){
				Q.push(p->right);
				layer.push(lay+1);
			}
        }
        return res;
    }
    
};

int main()
{
	
}

