class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int xr=0;
        for(int i:nums)xr^=i;
        return __builtin_popcount(xr^k);
    }
};