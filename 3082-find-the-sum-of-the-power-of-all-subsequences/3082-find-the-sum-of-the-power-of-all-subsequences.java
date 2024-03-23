class Solution {
   long mod = 1000000007;

    long power(long a, long b) {
        long res = 1;
        while (b > 0) {
            if ((b & 1) == 1)
                res = (res * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return res;
    }

    long sol(int[] nums, int k, long[][][] dp, int i, int count) {
        if (k == 0) {
            long ans = power(2, nums.length - count);
            return ans % mod;
        }
        if (i < 0)
            return 0;
        if (dp[i][k][count] != -1)
            return dp[i][k][count];
        long t = 0, n_t = 0;
        n_t = sol(nums, k, dp, i - 1, count);
        if (nums[i] <= k)
            t = sol(nums, k - nums[i], dp, i - 1, count + 1);
        return dp[i][k][count] = (t + n_t) % mod;
    }

    public int sumOfPower(int[] nums, int k) {
        long[][][] dp = new long[nums.length][k + 1][nums.length + 1];
        for (long[][] a : dp)
            for (long[] b : a)
                Arrays.fill(b, -1);
        return (int) (sol(nums, k, dp, nums.length - 1, 0) % mod);
    }
}