class Solution {
public:
    int func(vector<int>&arr,int k,int i,vector<int>&dp){
        if(i>=arr.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int ans=0;
        int M=arr[i];
        for(int j=i;j<i+k&&j<arr.size();j++){
            M=max(M,arr[j]);
            ans=max(ans,M*(j-i+1)+func(arr,k,j+1,dp));
        }
        return dp[i]=ans;
    } 
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int>dp(arr.size(),-1);
        return func(arr,k,0,dp);
    }
};