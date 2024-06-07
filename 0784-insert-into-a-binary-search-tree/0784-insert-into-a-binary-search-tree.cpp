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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root){TreeNode* node=new TreeNode(val);return node;}
        if(root->val>val){
            TreeNode* node=insertIntoBST(root->left,val);
                root->left=node;
            return root;
        }
        
             TreeNode* node=insertIntoBST(root->right,val);
            
                root->right=node;
            
            return root;
        
    }
};