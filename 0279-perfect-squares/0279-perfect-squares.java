import java.util.Arrays;

class Solution {
    public long sol(int[] v, int i, int n, int[][] dp) {
        if (n == 0) return 0;
        if (i < 0) return Integer.MAX_VALUE - 2;
        if (dp[i][n] != -1) return dp[i][n];
        
        long t = Integer.MAX_VALUE;
        long n_t = Integer.MAX_VALUE;
        
        if (v[i] <= n) t = sol(v, i, n % v[i], dp) + n / v[i];
        n_t = sol(v, i - 1, n, dp);
        
        return Math.min(t, n_t);
    }

    public int numSquares(int n) {
        int s = (int) Math.sqrt(n);
        
        int[] v = new int[s];
        int[][] dp = new int[s][n + 1];
        
        for (int[] row : dp) Arrays.fill(row, -1);
        
        for (int i = 0; i < s; i++) {
            v[i] = (int) Math.pow(i + 1, 2);
        }
        
        return (int) sol(v, s - 1, n, dp);
    }
}
