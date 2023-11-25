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
    bool func(TreeNode* root,long long left,long long right){
        if(!root){return true;}
        bool l=func(root->left,left,root->val);
        bool r=func(root->right,root->val,right);
        return left<root->val && root->val<right && l &&r;
    }
public:
    bool isValidBST(TreeNode* root) {
        return func(root,LONG_MIN,LONG_MAX);  
    }
};