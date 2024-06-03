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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root){return {};}
        queue<pair<TreeNode*,int>>q;
        vector<vector<int>>ans;
        q.push({root,0});
        int l=-1;
        while(!q.empty()){
            TreeNode* node=q.front().first;
            int lvl=q.front().second;
            q.pop();
            if(l!=lvl){
                ans.push_back({node->val});
                l=lvl;
            }
            else{
                ans[lvl].push_back(node->val);
            }
            if(node->left){
                q.push({node->left,lvl+1});
            }if(node->right){
                q.push({node->right,lvl+1});
            }

        }
        return ans;
    }
};