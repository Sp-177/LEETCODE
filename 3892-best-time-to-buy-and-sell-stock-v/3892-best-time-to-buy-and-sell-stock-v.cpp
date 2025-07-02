#define ll long long
class Solution {
public:
    ll maximumProfit(vector<int>& prices, ll k) {
        ll n = prices.size();

        // dp[index][k][mode]
        vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(k + 1, vector<ll>(3, LLONG_MIN)));

        // Base case: when index == n, only mode 0 is valid
        for (ll trans = 0; trans <= k; ++trans) {
            dp[n][trans][0] = 0;
            // dp[n][trans][1] = dp[n][trans][2] = LLONG_MIN (already set)
        }

        // Fill bottom-up
        for (ll index = n - 1; index >= 0; --index) {
            for (ll trans = 0; trans <= k; ++trans) {
                // Mode 0: neutral (can choose buy, sell, or skip)
                {
                    ll res = dp[index + 1][trans][0];  // skip
                    if (trans <= k) {
                        if (dp[index + 1][trans][2] != LLONG_MIN)
                            res = max(res, dp[index + 1][trans][2] + prices[index]); // sell
                        if (dp[index + 1][trans][1] != LLONG_MIN)
                            res = max(res, dp[index + 1][trans][1] - prices[index]); // buy
                    }
                    dp[index][trans][0] = res;
                }

                // Mode 1: just bought, must sell later
                if (trans <= k) {
                    ll res = dp[index + 1][trans][1];  // skip
                    if (trans >= 1 && dp[index + 1][trans - 1][0] != LLONG_MIN)
                        res = max(res, dp[index + 1][trans - 1][0] + prices[index]);  // sell & complete transaction
                    dp[index][trans][1] = res;
                }

                // Mode 2: just sold, must buy later
                if (trans <= k) {
                    ll res = dp[index + 1][trans][2];  // skip
                    if (trans >= 1 && dp[index + 1][trans - 1][0] != LLONG_MIN)
                        res = max(res, dp[index + 1][trans - 1][0] - prices[index]);  // buy & complete transaction
                    dp[index][trans][2] = res;
                }
            }
        }

        return max(0LL, dp[0][k][0]);  // Only neutral is valid to start
    }
};
