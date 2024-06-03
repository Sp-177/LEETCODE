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
    void sol(int x,int y,TreeNode*root, map<int,priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>>&m){
        if(!root){return;}
        m[y].push({x,root->val});
        sol(x+1,y-1,root->left,m);
        sol(x+1,y+1,root->right,m);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>>m;
        vector<vector<int>>ans;
        sol(0,0,root,m);
        for(auto i:m){
            vector<int>out;
            while(!i.second.empty()){
                out.push_back(i.second.top().second);
                i.second.pop();
            }
            ans.push_back(out);
        }
        return ans;
    }
};