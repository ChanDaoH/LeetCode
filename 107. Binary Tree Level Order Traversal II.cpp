/*
107. Binary Tree Level Order Traversal II
*/

#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:	
    vector<vector<int> > levelOrderBottom(TreeNode* root) {
        vector<vector<int> >res;
        vector<int> curlayer;
        queue<TreeNode*> q;
        TreeNode *p;
        if(root == NULL) return res;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
			p = q.front();
			q.pop();
			if( p == NULL ){
				res.insert(res.begin(),curlayer);
				curlayer.resize(0);
				if(q.size()>0){
					q.push(NULL);
				}
			}else{
				curlayer.push_back(p->val);
				if(p->left) q.push(p->left);
				if(p->right) q.push(p->right);
			}
        }
        return res;
    }
};

int main()
{
	
}















