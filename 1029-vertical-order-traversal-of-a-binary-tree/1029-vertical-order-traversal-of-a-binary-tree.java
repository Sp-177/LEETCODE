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
    private void sol(int x, int y, TreeNode root, Map<Integer, PriorityQueue<int[]>> map) {
        if (root == null) {
            return;
        }
        map.putIfAbsent(y, new PriorityQueue<>((a, b) -> {
            if (a[0] == b[0]) {
                return Integer.compare(a[1], b[1]);
            } else {
                return Integer.compare(a[0], b[0]);
            }
        }));
        map.get(y).offer(new int[]{x, root.val});
        sol(x + 1, y - 1, root.left, map);
        sol(x + 1, y + 1, root.right, map);
    }

    public List<List<Integer>> verticalTraversal(TreeNode root) {
        Map<Integer, PriorityQueue<int[]>> map = new TreeMap<>();
        List<List<Integer>> ans = new ArrayList<>();
        sol(0, 0, root, map);

        for (Map.Entry<Integer, PriorityQueue<int[]>> entry : map.entrySet()) {
            List<Integer> out = new ArrayList<>();
            PriorityQueue<int[]> pq = entry.getValue();
            while (!pq.isEmpty()) {
                out.add(pq.poll()[1]);
            }
            ans.add(out);
        }
        return ans;
    }
}