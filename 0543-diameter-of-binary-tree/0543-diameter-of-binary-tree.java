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
   public int diameterOfBinaryTree(TreeNode root) {
        int[] ans = new int[1];
        sol(root, ans);
        return ans[0];
    }
    
    private int sol(TreeNode root, int[] ans) {
        if (root == null) return 0;
        
        int[] left = new int[1];
        int[] right = new int[1];
        
        left[0] = sol(root.left, ans) + 1;
        right[0] = sol(root.right, ans) + 1;
        
        ans[0] = Math.max(ans[0], left[0] + right[0] - 2);
        
        return Math.max(left[0], right[0]);
    }
}