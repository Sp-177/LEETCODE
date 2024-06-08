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
    TreeNode* insert(TreeNode* root,int val){
        if(!root){
            TreeNode* node=new TreeNode(val);
            return node;
        }
        if(val<root->val){
            TreeNode* l=insert(root->left,val);
            if(l){root->left=l;}
            return NULL;
        }
        
            TreeNode* r=insert(root->right,val);
            if(r){root->right=r;}
            return NULL;
        
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root=new TreeNode(preorder[0]);
        for(int i=1;i<preorder.size();i++){
            insert(root,preorder[i]);
        }
        return root;
    }
};