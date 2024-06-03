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
    int sol(TreeNode* root,bool&ans){
        if(!root){return 0;}
        int lh=sol(root->left,ans);
        int rh=sol(root->right,ans);
        bool say=(abs(lh-rh)<=1?true:false);
        ans=ans&say;
        return max(lh,rh)+1;
    }
    bool isBalanced(TreeNode* root) {
        bool ans=true;
        sol(root,ans);
        return ans;
    }
};