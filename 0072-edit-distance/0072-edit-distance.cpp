class Solution {
public:
vector<vector<int>>dp;
    int func(string&w,string &v,int i,int j,int n,int m){
        // cout<<i<<" "<<j<<endl;
        if(j==m)return n-i;
        if(i==n)return m-j;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=INT_MAX-1;
        if(w[i]==v[j]){
            ans=func(w,v,i+1,j+1,n,m);
        }
        return dp[i][j]=min({ans,func(w,v,i+1,j+1,n,m)+1,func(w,v,i+1,j,n,m)+1,func(w,v,i,j+1,n,m)+1});

    }
    int minDistance(string w1, string w2) {
        int n=w1.size(),m=w2.size();
        // if(n==0)return m;
        dp.resize(n+1,vector<int>(m+1,INT_MAX-1));
        for(int i=0;i<=n;i++)dp[i][m]=n-i;
        for(int i=0;i<=m;i++)dp[n][i]=m-i;
        // return func(w1,w2,0,0,n,m);
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int ans=INT_MAX-1;
                if(w1[i]==w2[j]){
                 ans=dp[i+1][j+1];
                }
                 dp[i][j]=min({ans,dp[i+1][j+1]+1,dp[i+1][j]+1,dp[i][j+1]+1});
            }
        }
        return dp[0][0];
    }
};