class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string s2;
        int S=s.size();
        for(int i=S-1;i>=0;i--)s2=s2+s[i];
        vector<vector<int>>dp(S+1,vector<int>(S+1));
        for(int i=1;i<S+1;i++){
            for(int j=1;j<S+1;j++){
                if(s[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        return dp[S][S];
    }
};