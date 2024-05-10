import java.util.*;

class Solution {
    public List<Integer> topo(HashMap<Integer, List<Integer>> m, int[] indegree, int n) {
        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < n; i++)
            if (indegree[i] == 0)
                q.add(i);
        List<Integer> ans = new ArrayList<>();
        while (!q.isEmpty()) {
            int f = q.poll();
            ans.add(f);
            if (m.containsKey(f)) {
                for (int i : m.get(f)) {
                    indegree[i]--;
                    if (indegree[i] == 0)
                        q.add(i);
                }
            }
        }
        return ans;
    }

    public List<Integer> eventualSafeNodes(int[][] graph) {
        HashMap<Integer, List<Integer>> m = new HashMap<>();
        int[] indegree = new int[graph.length];
        for (int i = 0; i < graph.length; i++) {
            for (int j : graph[i])
                m.computeIfAbsent(j, k -> new ArrayList<>()).add(i);
            indegree[i] = graph[i].length;
        }
        List<Integer> ans = topo(m, indegree, graph.length);
        Collections.sort(ans);
        return ans;
    }
}
