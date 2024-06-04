/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sol(TreeNode*root,TreeNode*p,TreeNode*q){
        if(!root){return NULL;}
        TreeNode* l=sol(root->left,p,q);
        TreeNode* r=sol(root->right,p,q);
        if(root==p || root==q){return root;}
        if(l &&r){
            return root;
        }
        if(!l){
            return r;
        }
        else{
            return l;
        }
        return NULL;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        return sol(root,p,q);
    }
};