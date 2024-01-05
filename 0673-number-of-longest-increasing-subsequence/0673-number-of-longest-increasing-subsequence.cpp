class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
 vector<int>ans(nums.size(),1);
    vector<int>dp(nums.size(),1);
    int a=1;
    for(int i=1;i<nums.size();i++){
        for(int j=0;j<i;j++){
            if(nums[i]>nums[j]){
              if (dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                ans[i]=ans[j];
              }
              else if(dp[i] == dp[j] + 1){
                  ans[i]+=ans[j];
              }
            }
        }
        a=max(a,dp[i]);
    }
    int x=0;
    for(int i=0;i<nums.size();i++){
        if(a==dp[i]){
            x+=ans[i];
        }
    }
    return x;
    }
};