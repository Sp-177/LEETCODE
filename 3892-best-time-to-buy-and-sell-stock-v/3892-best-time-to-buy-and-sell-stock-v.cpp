#define ll long long
class Solution {
public:
    vector<vector<vector<ll>>> dp;

    ll func(vector<int>& prices, ll n, ll k, ll index, ll mode) {
        if (index == n || k == 0) {
            if (mode == 0) return 0;
            return LLONG_MIN;
        }

        if (dp[index][k][mode] != -1)
            return dp[index][k][mode];

        ll res = LLONG_MIN;

        if (mode == 0) {
            // Option 1: skip
            res = max(res, func(prices, n, k, index + 1, 0));

            // Option 2: try selling
            ll sell = func(prices, n, k, index + 1, 2);
            if (sell != LLONG_MIN)
                res = max(res, sell + prices[index]);

            // Option 3: try buying
            ll buy = func(prices, n, k, index + 1, 1);
            if (buy != LLONG_MIN)
                res = max(res, buy - prices[index]);

        } else if (mode == 2) {
            // Option 1: skip
            res = max(res, func(prices, n, k, index + 1, 2));

            // Option 2: must buy to complete transaction
            ll buy = func(prices, n, k - 1, index + 1, 0);
            if (buy != LLONG_MIN)
                res = max(res, buy - prices[index]);

        } else { // mode == 1
            // Option 1: skip
            res = max(res, func(prices, n, k, index + 1, 1));

            // Option 2: must sell to complete transaction
            ll sell = func(prices, n, k - 1, index + 1, 0);
            if (sell != LLONG_MIN)
                res = max(res, sell + prices[index]);
        }

        return dp[index][k][mode] = res;
    }

    ll maximumProfit(vector<int>& prices, ll k) {
        ll n = prices.size();
        dp.assign(n + 1, vector<vector<ll>>(k + 1, vector<ll>(3, -1)));
        return max(0LL, func(prices, n, k, 0, 0));  // ensure no negative overflow result
    }
};
