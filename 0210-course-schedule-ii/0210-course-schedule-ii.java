import java.util.*;

class Solution {
    public boolean dfs(int node, List<Integer> ans, boolean[] visit, boolean[][] adj, int n, boolean[] path) {
        visit[node] = true;
        path[node] = true;
        for (int i = 0; i < n; i++) {
            if (adj[node][i]) {
                if (i != node && path[i]) {
                    return false;
                }
                if (i != node && !visit[i]) {
                    if (!dfs(i, ans, visit, adj, n, path)) return false;
                }
            }
        }
        path[node] = false;
        ans.add(node);
        return true;
    }

    public int[] findOrder(int n, int[][] p) {
        List<Integer> ans = new ArrayList<>();
        boolean[] visit = new boolean[n];
        boolean[] path = new boolean[n];
        boolean[][] adj = new boolean[n][n];
        for (int[] i : p) {
            adj[i[1]][i[0]] = true;
        }
        for (int i = 0; i < n; i++) {
            if (!visit[i]) {
                if (!dfs(i, ans, visit, adj, n, path)) return new int[]{};
            }
        }
        Collections.reverse(ans);
        return ans.stream().mapToInt(Integer::intValue).toArray();
    }
}
