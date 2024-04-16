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
    public TreeNode addOneRow(TreeNode root, int val, int depth) {
        if (depth == 1) {
            TreeNode newRoot = new TreeNode(val);
            newRoot.left = root;
            
            return newRoot;
        }
        addOneRowHelper(root, val, depth, 1);
        return root;
    }

    private void addOneRowHelper(TreeNode root, int val, int depth, int curr) {
        if (root == null) return;
        if (curr + 1 == depth) {
            TreeNode newRowL = new TreeNode(val);
            TreeNode newRowR = new TreeNode(val);
            newRowL.left = root.left;
            newRowR.right = root.right;
            root.left = newRowL;
            root.right = newRowR;
            return;
        }

        addOneRowHelper(root.left, val, depth, curr + 1);
        addOneRowHelper(root.right, val, depth, curr + 1);
    }
}