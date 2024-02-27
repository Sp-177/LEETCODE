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
    int sol(TreeNode* root,int &ans){
        if(!root)return 0;
        int l=sol(root->left,ans)+1;
        int r=sol(root->right,ans)+1;
        ans=max(ans,l+r-2);
        return max(l,r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        sol(root,ans);
        return ans;
    }
};