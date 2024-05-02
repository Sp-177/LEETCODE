import java.util.*;

class Solution {
    public boolean bfs(Queue<Integer> q, List<List<Integer>> edges, int[] colored, int n) {
        while (!q.isEmpty()) {
            int node = q.poll();
            for (int i : edges.get(node)) {
                if (colored[i] == Math.abs(colored[node] - 1) || colored[i] == -1) {
                    if (colored[i] == -1) {
                        colored[i] = Math.abs(colored[node] - 1);
                        q.add(i);
                    }
                } else {
                    return false;
                }
            }
        }
        return true;
    }

    public boolean isBipartite(int[][] edges) {
        int n = edges.length;
        List<List<Integer>> adjList = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            adjList.add(new ArrayList<>());
            for (int j = 0; j < edges[i].length; j++) {
                adjList.get(i).add(edges[i][j]);
            }
        }

        int[] colored = new int[n];
        Arrays.fill(colored, -1);
        
        boolean ans = true;
        for (int i = 0; i < n; i++) {
            Queue<Integer> q = new LinkedList<>();
            if (colored[i] == -1) {
                q.add(i);
                colored[i] = 0;
                ans &= bfs(q, adjList, colored, n);
            }
            if (!ans) {
                return false;
            }
        }
        return ans;
    }
}
