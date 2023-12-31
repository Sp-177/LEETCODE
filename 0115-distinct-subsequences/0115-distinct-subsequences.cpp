class Solution {
public:
    int numDistinct(string s, string t) {
        long long m=1e9+7;
        vector<vector<long long int>>dp(s.size()+1,vector<long long int>(t.size()+1));
        for(int i=0;i<s.size();i++)dp[i][0]=1;
        for(int i=1;i<=s.size();i++){
            for(int j=1;j<=t.size();j++){
                long long int ta=0;
                long long int n_t=dp[i-1][j];
                if(s[i-1]==t[j-1]){
                    ta=dp[i-1][j-1];
                }
                dp[i][j]=(ta+n_t)%m;
            }
        }
        return dp[s.size()][t.size()];
    }

};