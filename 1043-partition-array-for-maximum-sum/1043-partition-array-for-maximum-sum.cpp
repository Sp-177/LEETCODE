class Solution {
public:
    int func(vector<int>&arr,int k,int i,int j,vector<vector<int>>&dp){
        if(i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=INT_MIN;
        int x=arr[i];
        for(int l=i;l<i+k&&l<=j;l++){
            x=max(arr[l],x);
            ans=max(ans,x*(l-i+1)+func(arr,k,l+1,j,dp));
        }
        return dp[i][j]=ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<vector<int>>dp(arr.size(),vector<int>(arr.size(),-1));
        return func(arr,k,0,arr.size()-1,dp);
    }
};