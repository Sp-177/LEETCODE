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
    TreeNode* extR(TreeNode* root){
        if(!root){return NULL;}
        TreeNode* ext=root;
                        while(ext->right){
                            ext=ext->right;
                        }
            return ext;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root){return NULL;}
        TreeNode* node=root;
        while(node){
            if(node->val==key || (node->left && node->left->val==key)||(node->right&&node->right->val==key) ){
                if(node->val==key){
                    root=(node->left?node->left:node->right);
                    if(node->left){
                        TreeNode* ext =extR(node->left);
                        ext->right=node->right;
                    }
                    break;
                }
                else if(node->left && node->left->val==key){
                    if(node->left->left){
                        TreeNode* ext =extR(node->left->left);
                        ext->right=node->left->right;
                        node->left=node->left->left;
                    }
                     else{node->left=node->left->right;}
                     break;
                    
                }
                else if(node->right&&node->right->val==key){
                     if(node->right->left){
                        TreeNode* ext =extR(node->right->left);
                        ext->right=node->right->right;
                        node->right=node->right->left;
                    }
                    else{node->right=node->right->right;}
                    break;
                }
            }
            else if(node->val>key){
                node=node->left;
            }
            else{
                node=node->right;
            }
        }
        return root;
    }
};