class Solution {
public:
    vector<vector<vector<int>>> dp;

    int func(vector<int>& prices, int n, int k, int index, int mode) {
        if (index >= n || k == 0) return 0;
        if (dp[index][k][mode] != -1) return dp[index][k][mode];

        if (mode == 1) {
            // Buy mode
            dp[index][k][mode] = max(
                func(prices, n, k, index + 1, 0) - prices[index],  // Buy
                func(prices, n, k, index + 1, 1)                   // Skip
            );
        } else {
            // Sell mode
            dp[index][k][mode] = max(
                func(prices, n, k - 1, index + 1, 1) + prices[index],  // Sell
                func(prices, n, k, index + 1, 0)                       // Skip
            );
        }

        return dp[index][k][mode];
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        dp.assign(n, vector<vector<int>>(k + 1, vector<int>(2, -1)));
        return func(prices, n, k, 0, 1); // Start at index 0 with buy mode
    }
};
