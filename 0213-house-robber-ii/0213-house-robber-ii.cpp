class Solution {
public:
    int sol(int n,vector<int>&nums,int index, vector<int>&dp){
        if(index>=n){return 0;}
        if(dp[index]!=-1){return dp[index];}
        int p=sol(n,nums,index+2,dp)+nums[index];
        int np=sol(n,nums,index+1,dp);
        return dp[index]=max(p,np);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){return nums[0];}
        vector<int>dp(n,-1),dp1(n,-1);
        return max(sol(n-1,nums,0,dp),sol(n,nums,1,dp1));
    }
};