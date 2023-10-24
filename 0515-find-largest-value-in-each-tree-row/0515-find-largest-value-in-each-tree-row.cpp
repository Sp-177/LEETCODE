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
    vector<int> largestValues(TreeNode* root) {
       
        vector<int>ans;
         if(!root){return ans;}
        queue<TreeNode*>q;
        q.push(root);
        int parent=1;
        int child=0;
        int a=INT_MIN;
        while(!q.empty()){
            TreeNode* temp=q.front();
            if(temp->left!=nullptr){
                q.push(temp->left);child++;
            }
            if(temp->right!=nullptr){
                q.push(temp->right);child++;
            }
            q.pop();
            a=max(a,temp->val);
            parent--;
            if(parent==0){
                ans.push_back(a);
                parent=child;
                child=0;
                a=INT_MIN;
            }

        }
        return ans;
    }
};