class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int>dp(nums.size(),0);
        int n=nums.size();
        for(int i=nums.size()-2;i>=0;i--){
            int jump=INT_MAX-1;
            for(int j=min(n-1,nums[i]+i);j>i;j--){
                // cout<<j<<endl;
                jump=min(jump,dp[j]);
                // cout<<jump<<",";
            }
            //  cout<<jump<<endl;
             
            dp[i]=jump+1;
        }
        return dp[0];
    }
};