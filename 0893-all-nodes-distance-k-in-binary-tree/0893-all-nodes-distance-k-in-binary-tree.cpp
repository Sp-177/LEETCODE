/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        set<TreeNode*>visit;
        map<TreeNode*,TreeNode*>par;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node->left){
                par[node->left]=node;
                q.push(node->left);
            }
            if(node->right){
                par[node->right]=node;
                q.push(node->right);
            }
        }
        queue<pair<TreeNode*,int>>q1;
        q1.push({target,0});
        vector<int>ans;
        while(!q1.empty()){
            TreeNode* node=q1.front().first;
            int dis=q1.front().second;
            q1.pop();
            visit.insert(node);
            if(dis==k){
                ans.push_back(node->val);
            }
            if(node->left && visit.find(node->left)==visit.end()){
                q1.push({node->left,dis+1});
            }
            if(node->right && visit.find(node->right)==visit.end()){
                q1.push({node->right,dis+1});
            }
            if(par.find(node)!=par.end() && visit.find(par[node])==visit.end()){
                q1.push({par[node],dis+1});
            }

        }
        return ans;
    }
};