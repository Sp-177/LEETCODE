class Solution {
public:
    // vector<vector<int>>dp;
    vector<int>dp1,dp2;
    // bool func(string &s,string &p,int i,int j,int n,int m){
    //     if(i>=n||j>=m){
    //     if(i==n&&j==m)return true;
    //     return false;
    //     }
    //     if(dp[i][j]!=-1)return dp[i][j];
    //     if(p[j]=='*'){
    //         return dp[i][j]=(func(s,p,i+1,j,n,m)||func(s,p,i+1,j+1,n,m)||func(s,p,i,j+1,n,m));
    //     }
    //     else if (p[j]=='?'||s[i]==p[j])return dp[i][j]=func(s,p,i+1,j+1,n,m);
        
    //     return dp[i][j]=false;

    // } 
    bool isMatch(string s, string p) {
        s=s+" ";
        p=p+" ";
        int n=s.size(),m=p.size();
        dp1.resize(m+1,0);
        dp2.resize(m+1,0);
        dp2[m]=1;
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(p[j]=='*')dp1[j]=(dp2[j]|dp2[j+1]||dp1[j+1]);
                else if (p[j]=='?'||s[i]==p[j])dp1[j]=dp2[j+1];
                else dp1[j]=false;
            }
            dp2=dp1;
        }

        return dp2[0];
    }
};