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
public class Solution {
    private int sol(TreeNode root, boolean[] ans) {
        if (root == null) {
            return 0;
        }
        int lh = sol(root.left, ans);
        int rh = sol(root.right, ans);
        boolean say = (Math.abs(lh - rh) <= 1);
        ans[0] = ans[0] && say;
        return Math.max(lh, rh) + 1;
    }

    public boolean isBalanced(TreeNode root) {
        boolean[] ans = {true};
        sol(root, ans);
        return ans[0];
    }
}