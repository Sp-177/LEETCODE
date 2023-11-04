/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    pair<int,int> aof(TreeNode* root,int&ans){
        pair<int,int>p;
        if(!root){return p;}
        p.first=root->val;
        p.second=1;
        pair<int,int>left=aof(root->left,ans);
        pair<int,int>right=aof(root->right,ans);
        p.first+=left.first+right.first;
        p.second+=left.second+right.second;
        if(root->val==p.first/p.second){ans++;}
        return p;
    }
    int averageOfSubtree(TreeNode* root) {
        int ans=0;
        aof(root,ans);
        return ans;
    }
};