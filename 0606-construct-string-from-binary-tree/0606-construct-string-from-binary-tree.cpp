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
    private:
        string func(TreeNode* root){
            if(!root){return "";}
            string l,r;
            if(root->left || root->right){
                l='('+func(root->left)+')';
            }
            if(root->right){
                
                r='('+func(root->right)+')';
            }
            return to_string(root->val)+l+r;
        }
public:
    string tree2str(TreeNode* root) {
        return func(root);
    }
};