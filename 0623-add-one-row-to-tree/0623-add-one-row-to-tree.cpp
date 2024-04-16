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
    void sol(TreeNode* root, int val, int depth,int curr){
         if(!root)return;
        if(curr+1==depth){
            TreeNode* newRowL=new TreeNode(val);
            TreeNode* newRowR=new TreeNode(val);
            newRowL->left=root->left;
            newRowR->right=root->right;
            root->left=newRowL;
            root->right=newRowR;
            return;
        }
       
        sol(root->left,val,depth,curr+1);
        sol(root->right,val,depth,curr+1);

    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* newroot=new TreeNode(val);
            newroot->left=root;
            return newroot;
        }
        sol(root,val,depth,1);
        return root;
    }
};