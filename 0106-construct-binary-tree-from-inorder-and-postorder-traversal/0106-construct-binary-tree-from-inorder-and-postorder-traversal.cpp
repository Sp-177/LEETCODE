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
TreeNode* sol(vector<int>& inorder, vector<int>& postorder,int start,int end,int ind_post){
    if(start<end ||start<0||end<0||ind_post<0){return NULL;}
    // cout<<start<<' '<<end<<' '<<ind_post<<endl;
    TreeNode* root=new TreeNode();
    for(int i=start;i>=end;i--){
        if(postorder[ind_post]==inorder[i]){
            root->val=inorder[i];
            root->right=sol(inorder,postorder,start,i+1,ind_post-1);
            root->left=sol(inorder,postorder,i-1,end,ind_post-(start-i)-1);
            break;
        }

    }
    return root;
}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return sol(inorder,postorder,inorder.size()-1,0,postorder.size()-1);
    }
};