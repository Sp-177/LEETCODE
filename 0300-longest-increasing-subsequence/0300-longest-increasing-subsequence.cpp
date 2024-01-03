class Solution {
public:
    int func(vector<int>&nums,int n,int i,int prev,vector<vector<int>>&dp){
    if(i==n)return 0;
    int t=0;
    if(prev!=-1&&dp[i][prev+1]!=-1)return dp[i][prev+1];
    if(prev==-1||nums[prev]<nums[i] )t=func(nums,n,i+1,i,dp)+1;
    int n_t=func(nums,n,i+1,prev,dp);
    return dp[i][prev+1]=max(t,n_t);
}
    int lengthOfLIS(vector<int>& nums) {
    vector<vector<int>>dp(nums.size(),vector<int>(nums.size()+1,-1));
    return func(nums,nums.size(),0,-1,dp);
    }
};