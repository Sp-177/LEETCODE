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
    int func(TreeNode* root,vector<int>&v){
        if(!root)return 0;
        ++v[root->val];
        if(!root->left && !root->right){
            int odd=0;
            for(int i=1;i<=9;i++){
                cout<<v[i];
                if(v[i]%2!=0)odd++;
            }
            --v[root->val];
            if(odd==1 || odd==0)return 1;
            return 0;
        }
        int l=func(root->left,v);
        int r=func(root->right,v);
        --v[root->val];
        return l+r;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int>v(10,0);
        return func(root,v);
    }
};