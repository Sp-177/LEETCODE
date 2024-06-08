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
    bool sol(TreeNode* root,int k,unordered_map<int,int>&m){
        if(!root){return false;}
        m[root->val]++;
        bool s1=sol(root->left,k,m);
        bool s2=false;
        if(!s1){s2=sol(root->right,k,m);}
        if(m[k-root->val]>0){if(root->val==k-root->val && m[root->val]>1){return true;}else if(root->val!=k-root->val){return true;}}
        return s1||s2;
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int,int>m;
        return sol(root,k,m);
    }
};