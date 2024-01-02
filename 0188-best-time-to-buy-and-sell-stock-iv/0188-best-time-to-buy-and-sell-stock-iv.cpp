class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
         vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<=1;j++){
            for(int l=1;l<=k;l++){
                int n_t=dp[i+1][j][l];
                int t=0;
                if(j==1){
                    t=-prices[i]+dp[i+1][0][l];
                }
                else{
                    t=prices[i]+dp[i+1][1][l-1];
                }
                dp[i][j][l]=max(t,n_t);
            }
        }
    }
    return dp[0][1][k];
    }
};