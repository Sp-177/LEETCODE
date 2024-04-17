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
   public String smallestFromLeaf(TreeNode root) {
        return sol(root, "");
    }

    private String sol(TreeNode root, String ans) {
        if (root == null) return "";
        if (root.left == null && root.right == null) {
            ans = (char) (root.val + 'a') + ans;
            return ans;
        }
        ans = (char) (root.val + 'a') + ans;
        String left = sol(root.left, ans);
        String right = sol(root.right, ans);
        String a = (left.equals("")) ? right : left;
        String b = (right.equals("")) ? left : right;
        return a.compareTo(b) < 0 ? a : b;
    }
}