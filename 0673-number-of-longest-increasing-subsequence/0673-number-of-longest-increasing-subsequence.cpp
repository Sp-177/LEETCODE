class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1),cnt(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    if(dp[j]+1>dp[i]){
                        dp[i]=dp[j]+1;
                        cnt[i]=cnt[j];
                    }
                    else if(dp[j]+1==dp[i])cnt[i]+=cnt[j];
                }
            }
        }
        int ans=0;
        int lis=*max_element(dp.begin(),dp.end());
        for(int i=0;i<n;i++){
            if(dp[i]==lis)ans+=cnt[i];
        // cout<<dp[i]<<" "<<cnt[i]<<endl;
        }
        return ans;
    }
};