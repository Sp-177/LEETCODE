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
    private:
    int func(TreeNode* root,int&Maxi){
        if(!root){return 0;}
        int left=max(func(root->left,Maxi),0);
        int right=max(func(root->right,Maxi),0);
        Maxi=max(Maxi,left+right+root->val);
        return max(left+root->val,root->val+right);
        
    }
public:
    int maxPathSum(TreeNode* root) {
        int Maxi=INT_MIN;
        int ans=func(root,Maxi);
        return max(ans,Maxi);

    }
};