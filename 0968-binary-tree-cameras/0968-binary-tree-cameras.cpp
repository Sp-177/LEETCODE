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
    int func(TreeNode* root,TreeNode* head){
        if(!root){return 0;}
        int l=func(root->left,root);
        int r=func(root->right,root);
        if(root->left){
            if(root->left->val!=1 &&root->left->val!=2){root->val=1;if(head){head->val=2;} return 1+l+r;}
            else if(root->left->val==1){
                root->val=2;
            }
             else if(!head &&root->val!=2){root->val=1;return l+r+1;}
           
        }
        if(root->right){
             if(root->right->val!=1&&root->right->val!=2 ){root->val=1;
             if(head){head->val=2;}
             return 1+l+r;}
              else if(root->right->val==1){
                root->val=2;
            }
            else if(!head &&root->val!=2){root->val=1;return l+r+1;}
        }
        return l+r;}
public:
    int minCameraCover(TreeNode* root) {
        if(!root){return 0;}
        if(!root->left&&!root->right){return 1;}
        return func(root,NULL);
    }
};