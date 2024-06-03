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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        if (root == null) {
            return new ArrayList<>();
        }

        Queue<Pair<TreeNode, Integer>> q = new LinkedList<>();
        List<List<Integer>> ans = new ArrayList<>();
        q.add(new Pair<>(root, 0));
        int l = -1;

        while (!q.isEmpty()) {
            TreeNode node = q.peek().getKey();
            int lvl = q.peek().getValue();
            q.poll();

            if (l != lvl) {
                ans.add(new ArrayList<>(Collections.singletonList(node.val)));
                l = lvl;
            } else {
                ans.get(lvl).add(node.val);
            }

            if (node.left != null) {
                q.add(new Pair<>(node.left, lvl + 1));
            }
            if (node.right != null) {
                q.add(new Pair<>(node.right, lvl + 1));
            }
        }

        for (int j = 0; j < ans.size(); j++) {
            if (j % 2 == 1) {
                Collections.reverse(ans.get(j));
            }
        }
        return ans;
    }

    // Utility class to store pairs of TreeNode and level
    private static class Pair<K, V> {
        private K key;
        private V value;

        public Pair(K key, V value) {
            this.key = key;
            this.value = value;
        }

        public K getKey() {
            return key;
        }

        public V getValue() {
            return value;
        }
    }
}