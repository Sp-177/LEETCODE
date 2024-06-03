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
    void sol(int h,TreeNode* root,map<int,int>&m,vector<int>&ans){
        if(!root){return ;}
        if(m[h]==0){
            m[h]=1;
            ans.push_back(root->val);
        }
        sol(h+1,root->right,m,ans);
        sol(h+1,root->left,m,ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        map<int,int>m;
        vector<int>ans;
        sol(1,root,m,ans);
        return ans;
        
    }
};