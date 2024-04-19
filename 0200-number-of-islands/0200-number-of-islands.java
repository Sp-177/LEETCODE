class Solution {
     private void dfs(char[][] grid, boolean[][] visit, int m, int n, int i, int j) {
        if (i < 0 || j < 0 || i >= m || j >= n) return;
        if (grid[i][j] == '0' || visit[i][j]) return;
        visit[i][j] = true;
        dfs(grid, visit, m, n, i + 1, j);
        dfs(grid, visit, m, n, i, j + 1);
        dfs(grid, visit, m, n, i, j - 1);
        dfs(grid, visit, m, n, i - 1, j);
    }

    public int numIslands(char[][] grid) {
        int ans = 0;
        int m = grid.length;
        if (m == 0) return 0;
        int n = grid[0].length;
        boolean[][] visit = new boolean[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && !visit[i][j]) {
                    ans++;
                    dfs(grid, visit, m, n, i, j);
                }
            }
        }
        return ans;
    }
}