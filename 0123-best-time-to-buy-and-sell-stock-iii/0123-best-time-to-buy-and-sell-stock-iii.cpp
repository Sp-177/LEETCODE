class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>>dp(prices.size()+1,vector<vector<int>>(2,vector<int>(3,0)));
    for(int i=prices.size()-1;i>=0;i--){
        for(int j=1;j>=0;j--){
            for(int k=1;k<=2;k++){
                 if(j==0){
                    int t=0-prices[i]+dp[i+1][1][k];
                    int n_t=dp[i+1][j][k];
                    dp[i][j][k]=max(t,n_t);
                }
                else{
                int t=prices[i]+dp[i+1][0][k-1];
                int n_t=dp[i+1][j][k];
                dp[i][j][k]=max(t,n_t);
                }
            }
        }
    }
    return dp[0][0][2];
    }
};