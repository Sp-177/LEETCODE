/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public TreeNode sol(int[] preorder, int[] inorder, int start, int end, int idx_pre) {
        if (start > end || start < 0 || end < 0) {
            return null;
        }
        TreeNode root = new TreeNode();
        for (int i = start; i <= end; i++) {
            if (preorder[idx_pre] == inorder[i]) {
                root.val = inorder[i];
                root.left = sol(preorder, inorder, start, i - 1, 1 + idx_pre);
                root.right = sol(preorder, inorder, i + 1, end, (i - start) + 1 + idx_pre);
                break;
            }
        }
        return root;
    }

    public TreeNode buildTree(int[] preorder, int[] inorder) {
        return sol(preorder, inorder, 0, inorder.length - 1, 0);
    }
}