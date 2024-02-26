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
    bool isSameTree(TreeNode* p, TreeNode* q) {
       if(!p &&!q)return true;
        if((!p && q)||(!q &&p))return false;
        bool s1=isSameTree(p->left,q->left);
        bool s2=isSameTree(p->right,q->right);
        return s1&&s2&&(p->val==q->val);
    }
};