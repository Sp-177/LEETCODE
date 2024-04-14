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
    int sol(TreeNode* root){
        if(!root)return 0;
        int l=0,r=0;
        if(root->left){
            if(!root->left->left && !root->left->right)l=root->left->val;
            else l=sol(root->left);
        }
        r=sol(root->right);
        return l+r;


    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root||( !root->left && !root->right))return 0;
        return sol(root);
    }
};