class Solution {
    public int numEnclaves(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        boolean[][] visit = new boolean[n][m];
        Queue<int[]> q = new LinkedList<>();
        
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 1 && !visit[i][0]) {
                q.add(new int[]{i, 0});
                visit[i][0] = true;
            }
            if (grid[i][m - 1] == 1 && !visit[i][m - 1]) {
                q.add(new int[]{i, m - 1});
                visit[i][m - 1] = true;
            }
        }
        
        for (int i = 0; i < m; i++) {
            if (grid[0][i] == 1 && !visit[0][i]) {
                q.add(new int[]{0, i});
                visit[0][i] = true;
            }
            if (grid[n - 1][i] == 1 && !visit[n - 1][i]) {
                q.add(new int[]{n - 1, i});
                visit[n - 1][i] = true;
            }
        }
        
        int[][] directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!q.isEmpty()) {
            int[] top = q.poll();
            int i = top[0], j = top[1];
            
            for (int[] dir : directions) {
                int ni = i + dir[0];
                int nj = j + dir[1];
                if (ni >= 0 && ni < n && nj >= 0 && nj < m && !visit[ni][nj] && grid[ni][nj] == 1) {
                    visit[ni][nj] = true;
                    q.add(new int[]{ni, nj});
                }
            }
        }
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !visit[i][j]) {
                    ans++;
                }
            }
        }
        return ans;
    }
}