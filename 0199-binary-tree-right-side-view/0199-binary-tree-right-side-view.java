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
    private void sol(int h, TreeNode root, List<Integer> ans) {
        if (root == null) {
            return;
        }
        if (ans.size() <= h) {
            ans.add(root.val);
        }
        sol(h + 1, root.right, ans);
        sol(h + 1, root.left, ans);
    }

    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> ans = new ArrayList<>();
        sol(0, root, ans);
        return ans;
    }
}