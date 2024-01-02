class Solution {
public:
int func(vector<int>&prices,int buy,int i, vector<vector<int>>&dp){
    if(i>=prices.size())return 0;
    if(dp[i][buy]!=-1)return dp[i][buy];
    if(buy==1){
        return dp[i][buy]=max(-prices[i]+func(prices,0,i+1,dp),func(prices,1,i+1,dp));
    }
    else{
        return dp[i][buy]=max(prices[i]+func(prices,1,i+2,dp),func(prices,0,i+1,dp));
    }
}
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size()+1,vector<int>(2,-1));
    return func(prices,1,0,dp);
    }
};