class Solution {
public:
    int func(int i,int j,vector<int>&v,vector<vector<int>>&dp){
        if(i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int m=INT_MIN;
        for(int k=i;k<=j;k++){
            int x=v[i-1];
            int y=v[j+1];
            m=max(m,x*y*v[k]+func(i,k-1,v,dp)+func(k+1,j,v,dp));
        }
        return dp[i][j]=m;
    } 
    int maxCoins(vector<int>& nums) {
        vector<int>v;
        v.push_back(1);
        v.insert(v.end(),nums.begin(),nums.end());
        v.push_back(1);
        vector<vector<int>>dp(v.size(),vector<int>(v.size(),-1));
        return func(1,nums.size(),v,dp);
    }
};