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
    public TreeNode sol(TreeNode root) {
        if (root == null) {
            return null;
        }

        TreeNode newRight = root.right;
        if (root.left != null) {
            TreeNode nR = sol(root.left);
            root.right = root.left;
            root.left = null;
            if (nR != null) {
                nR.right = newRight;
            }
        }

        TreeNode returningRight = sol(root.right);
        if (root.left == null && root.right == null) {
            return root;
        }
        return returningRight;
    }

    public void flatten(TreeNode root) {
        sol(root);
    }
}
