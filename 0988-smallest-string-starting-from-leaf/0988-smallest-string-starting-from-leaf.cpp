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
    string sol(TreeNode* root,string ans){
        if(!root)return "";
        if(!root->left && !root->right){ans=char(root->val+'a')+ans;return ans;}
        ans=char(root->val+'a')+ans;
        string left=sol(root->left,ans);
        string right=sol(root->right,ans);
        string a=(left=="")?right:left;
        string b=(right=="")?left:right;
        return min(a,b);
    }
    string smallestFromLeaf(TreeNode* root) {
        return sol(root,"");
    }
};