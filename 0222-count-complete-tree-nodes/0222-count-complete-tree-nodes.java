/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() { val = 0; }
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

class Solution {
    private int leftHeight(TreeNode root) {
        if (root == null) {
            return 0;
        }
        return leftHeight(root.left) + 1;
    }

    private int rightHeight(TreeNode root) {
        if (root == null) {
            return 0;
        }
        return rightHeight(root.right) + 1;
    }

    public int countNodes(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int left = leftHeight(root);
        int right = rightHeight(root);
        if (left == right) {
            return (1 << left) - 1;
        }
        return 1 + countNodes(root.left) + countNodes(root.right);
    }
}
