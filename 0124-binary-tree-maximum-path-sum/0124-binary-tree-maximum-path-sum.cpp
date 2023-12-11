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
        int left=func(root->left,Maxi);
        int right=func(root->right,Maxi);
        Maxi=max(Maxi,max(right+root->val,left+root->val));
        Maxi=max(Maxi,max(left+right+root->val,root->val));
        return max(root->val,max(left+root->val,root->val+right));
        
    }
public:
    int maxPathSum(TreeNode* root) {
        int Maxi=INT_MIN;
        int ans=func(root,Maxi);
        return max(ans,Maxi);

    }
};