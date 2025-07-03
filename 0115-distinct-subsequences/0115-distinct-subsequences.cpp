class Solution {
public:
    vector<vector<int>>dp;
    int func(string&s,string&t,int i,int j,int n,int m){
        if(j==m)return 1;
        if(i>=n)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int ta=0,nt=0;
        if(s[i]==t[j])ta=func(s,t,i+1,j+1,n,m);
        nt=func(s,t,i+1,j,n,m);
        return dp[i][j]=ta+nt;
    }
    int numDistinct(string s, string t) {
        int n=s.size(),m=t.size();
        dp.resize(n,vector<int>(m,-1));
        return func(s,t,0,0,n,m);
    }
};