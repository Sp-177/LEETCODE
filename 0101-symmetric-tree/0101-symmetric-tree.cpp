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
bool sol(TreeNode* left,TreeNode*right){
    if(!left &&!right){return true;}
    else if(!left &&right){return false;}
    else if(!right && left ){return false;}
    if(left->val==right->val){
        bool s1=sol(left->left,right->right);
        bool s2=sol(left->right,right->left);
        return s1&&s2;
    }
    return false;
}
    bool isSymmetric(TreeNode* root) {
        if(!root)return true;
        return sol(root->left,root->right);
    }
};