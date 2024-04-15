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
    public void sol(TreeNode root, int num, int[] ans) {
        if (root == null) return;
        num = num * 10 + root.val;
        if (root.left == null && root.right == null) {
            ans[0] += num;
            return;
        }
        sol(root.left, num, ans);
        sol(root.right, num, ans);
    }

    public int sumNumbers(TreeNode root) {
        int[] ans = new int[1];
        ans[0] = 0;
        sol(root, 0, ans);
        return ans[0];
    }
}