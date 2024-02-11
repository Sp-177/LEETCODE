public class Solution {
    public int sol(int[][] grid, int i, int j, int k, int[][][] dp) {
        if (i < 0 || j < 0 || i >= grid.length || j >= grid[0].length || k >= grid[0].length || k < 0 || j == k) return 0;
        if (i == grid.length - 1 && j >= 0 && j <= grid[0].length - 1 && k >= 0 && k <= grid[0].length - 1) {
            return grid[i][j] + grid[i][k];
        }
        if (dp[i][j][k] != -1) return dp[i][j][k];
        int[] a = {-1, 0, 1};
        int sum = grid[i][j] + grid[i][k];
        int ans = 0;
        for (int l = 0; l < 3; l++) {
            for (int m = 0; m < 3; m++) {
                ans = Math.max(ans, sol(grid, i + 1, j + a[l], k + a[m], dp) + sum);
            }
        }
        return dp[i][j][k] = ans;
    }

    public int cherryPickup(int[][] grid) {
        int[][][] dp = new int[grid.length][grid[0].length][grid[0].length];
        for (int[][] layer2D : dp) {
            for (int[] layer1D : layer2D) {
                Arrays.fill(layer1D, -1);
            }
        }
        return sol(grid, 0, 0, grid[0].length - 1, dp);
    }
}
