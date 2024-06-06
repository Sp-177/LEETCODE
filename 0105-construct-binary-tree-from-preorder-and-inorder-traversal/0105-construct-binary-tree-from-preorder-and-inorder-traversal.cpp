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
    TreeNode* sol(vector<int>&preorder,vector<int>&inorder,int start,int end,int idx_pre){
        if(start>end || start<0 ||end<0){return NULL;}
        TreeNode* root=new TreeNode();
        for(int i=start;i<=end;i++){
            
            if(preorder[idx_pre]==inorder[i]){
                root->val=inorder[i];
                root->left=sol(preorder,inorder,start,i-1,1+idx_pre);
                
                root->right=sol(preorder,inorder,i+1,end,(i-start)+1+idx_pre);
                break;
            }
        }
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return sol(preorder,inorder,0,inorder.size()-1,0);
    }
};