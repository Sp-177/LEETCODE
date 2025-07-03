class Solution {
public:
    int minDistance(string w, string v) {
        int n=w.size(),m=v.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(w[i-1]==v[j-1])dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return n+m-2*dp[n][m];
    }
};