/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

import java.util.*;

class Solution {
    public List<Integer> distanceK(TreeNode root, TreeNode target, int k) {
        Set<TreeNode> visited = new HashSet<>();
        Map<TreeNode, TreeNode> parentMap = new HashMap<>();
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        
        // Building the parent map
        while (!queue.isEmpty()) {
            TreeNode node = queue.poll();
            if (node.left != null) {
                parentMap.put(node.left, node);
                queue.add(node.left);
            }
            if (node.right != null) {
                parentMap.put(node.right, node);
                queue.add(node.right);
            }
        }

        Queue<Pair<TreeNode, Integer>> queue1 = new LinkedList<>();
        queue1.add(new Pair<>(target, 0));
        List<Integer> result = new ArrayList<>();
        
        // BFS to find nodes at distance K
        while (!queue1.isEmpty()) {
            Pair<TreeNode, Integer> current = queue1.poll();
            TreeNode node = current.getKey();
            int distance = current.getValue();
            
            visited.add(node);
            if (distance == k) {
                result.add(node.val);
            }
            if (node.left != null && !visited.contains(node.left)) {
                queue1.add(new Pair<>(node.left, distance + 1));
            }
            if (node.right != null && !visited.contains(node.right)) {
                queue1.add(new Pair<>(node.right, distance + 1));
            }
            if (parentMap.containsKey(node) && !visited.contains(parentMap.get(node))) {
                queue1.add(new Pair<>(parentMap.get(node), distance + 1));
            }
        }
        
        return result;
    }
}

// Helper class to store pairs
class Pair<K, V> {
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
