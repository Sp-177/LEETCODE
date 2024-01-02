class Solution {
public:
int func(vector<int>&prices,int i,int j,int fee,vector<vector<int>>&dp){
	
	if(i>=prices.size())return 0;
	if(dp[i][j]!=-1)return dp[i][j];
	if(j==1){
		return dp[i][j]=max(-prices[i]+func(prices,i+1,0,fee,dp),func(prices,i+1,1,fee,dp));
	}
	else return dp[i][j]=max(prices[i]+func(prices,i+1,1,fee,dp)-fee,func(prices,i+1,0,fee,dp));

}
    int maxProfit(vector<int>& prices, int fee) {
    vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
	return func(prices,0,1,fee,dp);
    }
};