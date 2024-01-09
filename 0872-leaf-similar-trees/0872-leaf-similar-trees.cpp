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
    void func(TreeNode* root,vector<int>&seq){
        if(!root)return;
        if(!root->left &&!root->right){seq.push_back(root->val);return;}
        func(root->left,seq);
        func(root->right,seq);
    } 
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>a,b;
        func(root1,a);func(root2,b);
        if(a.size()!=b.size())return false;
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i])return false;
        }
        return true;
    }
};