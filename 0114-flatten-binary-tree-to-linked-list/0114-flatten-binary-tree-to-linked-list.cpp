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
    TreeNode* sol(TreeNode* root){
        if(!root){return NULL;}
        
        TreeNode* new_r=root->right;
        if(root->left){
            TreeNode* nR=sol(root->left);
            root->right=root->left;
            root->left=NULL;
            if(nR)nR->right=new_r;
        }
        
        TreeNode* returningR=sol(root->right);
        if(!root->left&&!root->right){return root;}
        return returningR;
        
    }
    void flatten(TreeNode* root) {
        sol(root);
        
    }
};