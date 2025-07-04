class Solution {
public:
    vector<vector<int>>dp;
    bool func(string&s,string&p,int i,int j,int n,int m){
        // cout<<i<<" "<<j<<endl;
        if(i>n||j>m)return false;
        if(i==n&&j==m)return true;
        if(dp[i][j]!=-1)return dp[i][j];
        bool ans=false;
        if(j+1<m){
            if(p[j+1]=='*'){
                if((i<n&&s[i]==p[j])||p[j]=='.')ans=ans||func(s,p,i+1,j,n,m)||func(s,p,i+1,j+2,n,m);
                ans=ans||func(s,p,i,j+2,n,m);
            }
        }
        if((i<n&&s[i]==p[j])||p[j]=='.')ans=ans||func(s,p,i+1,j+1,n,m);
        return dp[i][j]=ans;
    }
    bool isMatch(string s, string p) {
        int n=s.size(),m=p.size();
        dp.resize(n+1,vector<int>(m+1,-1));
        return func(s,p,0,0,n,m);
    }
};