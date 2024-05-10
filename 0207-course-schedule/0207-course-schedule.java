import java.util.*;

class Solution {
    public int topo(int n, HashMap<Integer, List<Integer>> m, int[] indegree) {
        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < n; i++)
            if (indegree[i] == 0)
                q.add(i);
        List<Integer> ans = new ArrayList<>();
        while (!q.isEmpty()) {
            int f = q.poll();
            if (m.containsKey(f)) {
                for (int i : m.get(f)) {
                    indegree[i]--;
                    if (indegree[i] == 0)
                        q.add(i);
                }
            }
            ans.add(f);
        }
        return ans.size();
    }

    public boolean canFinish(int n, int[][] p) {
        HashMap<Integer, List<Integer>> m = new HashMap<>();
        int[] indegree = new int[n];
        for (int[] i : p) {
            m.computeIfAbsent(i[1], k -> new ArrayList<>()).add(i[0]);
            indegree[i[0]]++;
        }
        return n == topo(n, m, indegree);
    }
}
