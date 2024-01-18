class Solution {
public:
    int func(int i,int j,vector<int>&v,vector<vector<int>>&dp)
{
    if(i>j)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int m=INT_MAX;
    for(int k=i;k<=j;k++){
        m=min(m,v[j+1]-v[i-1]+func(i,k-1,v,dp)+func(k+1,j,v,dp));
    }
    return dp[i][j]=m;
}
    int minCost(int n, vector<int>& cuts) {
    vector<int>v;
    int c=cuts.size();
    v.push_back(0);
    v.push_back(n);
    v.insert(v.end(),cuts.begin(),cuts.end());
    sort(v.begin(),v.end());
    vector<vector<int>>dp(v.size(),vector<int>(v.size(),-1));
    return func(1,c,v,dp);
    }
};