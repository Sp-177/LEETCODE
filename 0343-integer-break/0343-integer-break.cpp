class Solution {
public:
    int integerBreak(int n) {
        vector<int>dp(n+1,1);
        for(int i=2;i<=n;i++){
            int y=0;
            int x=0;
            for(int j=1;j<i;j++){
                x=j;y=i-x;
                int num1=max(x,dp[x]);
                int num2=max(y,dp[y]);
                dp[i]=max(dp[i],num1*num2);
            }
        }
        return dp[n];
    }
};