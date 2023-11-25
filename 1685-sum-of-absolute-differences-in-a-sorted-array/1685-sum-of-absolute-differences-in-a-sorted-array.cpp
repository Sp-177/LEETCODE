class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        int right_sum=0;
        for(int i=0;i<n;i++){
            right_sum+=nums[i];
        }
        int left_sum=0;
        for(int i=0;i<n;i++){
            ans[i]=i*nums[i]-left_sum+right_sum-(n-i)*nums[i];
            left_sum+=nums[i];
            right_sum-=nums[i];
        }
        return ans;
    }
};