class Solution {

public:

    int longestPalindromeSubseq(string s) {
        if(s.size()==1)return 1;
        vector<vector<int>>dp(s.size(),vector<int>(s.size(),0));
        for(int i=0;i<s.size();i++)dp[i][i]=1;
        for(int i=s.size()-2;i>=0;i--){
            for(int j=1;j<s.size();j++){
                if(i>j){dp[i][j]=0;}
                else if(i==j){dp[i][j]=1;}
                else if(s[i]==s[j]){ dp[i][j]=2+dp[i+1][j-1];}
                else dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
               
            }
        }
        return dp[0][s.size()-1];
    }
};