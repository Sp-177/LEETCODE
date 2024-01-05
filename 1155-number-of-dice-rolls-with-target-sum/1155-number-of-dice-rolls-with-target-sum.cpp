class Solution {
public:
    long long m =1e9+7;
    long long func(int n, int k, int target, vector<vector<long long>>& dp) {
        if(target==0&&n==0)return 1;
        if (target == 0||n==0)return 0;
        long long t = 0;
        if (dp[n][target] != -1) return dp[n][target];
        for (int i = 1; i <= k; i++) {
            if (i <= target) {
                t = (t  + func(n - 1, k, target - i, dp) )%m ;
            }
        }
        return  dp[n][target]=t;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<long long>> dp(n + 1, vector<long long>(target + 1, -1));
        return func(n, k, target, dp);
    }
};