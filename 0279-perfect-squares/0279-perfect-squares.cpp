class Solution {
public:
    long long sol(vector<int>&v,int i,int n,vector<vector<int>>&dp){
       
        if(n==0)return 0;
        if(i<0)return INT_MAX-2;
        if(dp[i][n]!=-1)return dp[i][n];
        long long t=INT_MAX,n_t=INT_MAX;
        if(v[i]<=n)t=sol(v,i,n%v[i],dp)+n/v[i];
        n_t=sol(v,i-1,n,dp);
        return min(t,n_t);
        
    }
    int numSquares(int n) {
        int s=sqrt(n);
       
        vector<int>v(s);
        vector<vector<int>>dp(s,vector<int>(n+1,-1));
        for(int i=0;i<s;i++){v[i]=pow((i+1),2);}
        return sol(v,s-1,n,dp);
    }
};