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
    void sum(TreeNode* root,int&rs){
        if(!root)return;
        sum(root->right,rs);
        int t=rs;
        rs+=root->val;
        root->val+=t;
        sum(root->left,rs);
        
    }
    TreeNode* bstToGst(TreeNode* root) {
        int rs=0;
        sum(root,rs);
        return root;
    }
};