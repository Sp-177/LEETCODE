#define ll long long
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        ll n = nums.size();
        vector<ll> ps(n + 1, 0);
        // Initialize prefix sum
        for (int i = 0; i < n; i++) {
            ps[i + 1] = ps[i] + nums[i];
        }

        ll ans = 0;
        ll start = 0, end = 0;
        while (end < n) {
            ll sum = ps[end + 1] - ps[start];  // sum of subarray from start to end
            ll len = end - start + 1;
            while (start < end && sum * len >= k) {
                start++;
                sum = ps[end + 1] - ps[start];  // recalculate sum after incrementing start
                len = end - start + 1;
            }
            if (sum * len < k) {
                ans += (end - start + 1);
            }
            end++;
        }
        return ans;
    }
};
