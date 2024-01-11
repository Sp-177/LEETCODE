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
int func(TreeNode* root,vector<int>&anc){
    if(!root)return 0;
    anc.push_back(root->val);
    int l=func(root->left,anc);
    int r=func(root->right,anc);
    anc.pop_back();
    int c=0;
    for(auto i:anc)c=max(c,abs(root->val-i));
    return max(c,max(l,r));
}
    int maxAncestorDiff(TreeNode* root) {
        vector<int>anc;
        return func(root,anc);
    }
};