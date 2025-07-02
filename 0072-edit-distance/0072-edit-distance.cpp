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
        if(n==0)return m;
        dp.resize(n,vector<int>(m,-1));
        return func(w1,w2,0,0,n,m);
    }
};