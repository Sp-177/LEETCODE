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
    private void sol(int h, TreeNode root, Map<Integer, Boolean> m, List<Integer> ans) {
        if (root == null) {
            return;
        }
        if (!m.getOrDefault(h, false)) {
            m.put(h, true);
            ans.add(root.val);
        }
        sol(h + 1, root.right, m, ans);
        sol(h + 1, root.left, m, ans);
    }

    public List<Integer> rightSideView(TreeNode root) {
        Map<Integer, Boolean> m = new HashMap<>();
        List<Integer> ans = new ArrayList<>();
        sol(1, root, m, ans);
        return ans;
    }
}