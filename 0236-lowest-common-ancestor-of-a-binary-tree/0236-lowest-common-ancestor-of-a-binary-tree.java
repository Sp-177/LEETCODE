/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    private TreeNode sol(TreeNode root, TreeNode p, TreeNode q) {
        if (root == null) {
            return null;
        }
        TreeNode l = sol(root.left, p, q);
        TreeNode r = sol(root.right, p, q);
        if (root == p || root == q) {
            return root;
        }
        if (l != null && r != null) {
            return root;
        }
        return l != null ? l : r;
    }

    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        return sol(root, p, q);
    }
}
