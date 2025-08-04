class Solution {
public:
    int ans = 0;

    void merge(vector<int>& nums, int s, int mid, int e) {
        int cnt = 0;
        for (int i = mid + 1; i <= e; i++) {
            auto it = lower_bound(nums.begin() + s, nums.begin() + mid + 1, 2LL * nums[i] + 1);
            if (it != nums.begin() + mid + 1) {
                int ind = it - nums.begin();
                cnt += (mid - ind + 1);
            }
        }

        ans += cnt;

        vector<int> merger;
        int i = s, j = mid + 1;
        while (i <= mid && j <= e) {
            if (nums[i] < nums[j]) {
                merger.push_back(nums[i++]);
            } else {
                merger.push_back(nums[j++]);
            }
        }
        while (i <= mid) merger.push_back(nums[i++]);
        while (j <= e) merger.push_back(nums[j++]);

        for (int k = 0; k < merger.size(); ++k)
            nums[s + k] = merger[k];
    }

    void dnc(vector<int>& nums, int s, int e) {
        if (s >= e) return;
        int mid = (s + e) / 2;
        dnc(nums, s, mid);
        dnc(nums, mid + 1, e);
        merge(nums, s, mid, e);
    }

    int reversePairs(vector<int>& nums) {
        dnc(nums, 0, nums.size() - 1);
        return ans;
    }
};
