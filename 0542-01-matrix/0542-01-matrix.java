class Solution {
    public int[][] updateMatrix(int[][] mat) {
        int n = mat.length;
        int m = mat[0].length;
        int[][] ans = new int[n][m];
        boolean[][] visit = new boolean[n][m];
        Queue<int[]> q = new LinkedList<>();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    q.add(new int[]{i, j, 0});
                    visit[i][j] = true;
                }
            }
        }
        
        int[][] directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!q.isEmpty()) {
            int[] top = q.poll();
            int i = top[0], j = top[1], v = top[2];
            ans[i][j] = v;
            
            for (int[] dir : directions) {
                int ni = i + dir[0];
                int nj = j + dir[1];
                if (ni >= 0 && ni < n && nj >= 0 && nj < m && !visit[ni][nj]) {
                    visit[ni][nj] = true;
                    q.add(new int[]{ni, nj, v + 1});
                }
            }
        }
        
        return ans;}
}