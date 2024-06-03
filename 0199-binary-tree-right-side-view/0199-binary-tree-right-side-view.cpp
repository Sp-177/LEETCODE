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
    void sol(int h,TreeNode* root,vector<int>&ans){
        if(!root){return ;}
        if(ans.size()<=h){
            ans.push_back(root->val);
        }
        sol(h+1,root->right,ans);
        sol(h+1,root->left,ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        sol(0,root,ans);
        return ans;
        
    }
};