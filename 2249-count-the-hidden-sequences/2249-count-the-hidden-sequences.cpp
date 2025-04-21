#define ll long long
#include <vector>
#include <algorithm>

class Solution {
public:
    ll numberOfArrays(std::vector<int>& dif, ll lower, ll upper) {
        ll n = dif.size();
        std::vector<ll> prefix(n + 1, 0);

        for (ll i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + dif[i];
        }

        std::sort(prefix.begin(), prefix.end());

        ll k1 = prefix[0], k2 = prefix[n];
        ll x_greater_than = lower - k1;
        ll x_less_than = upper - k2;

        return std::max(0LL, (x_less_than - x_greater_than + 1));
    }
};
