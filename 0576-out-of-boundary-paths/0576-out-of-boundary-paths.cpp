class Solution {
public:
 long long mod=1e9+7;
    long long func(int m,int n,int move,int maxMove,int startRow,int startColumn,vector<vector<int>>&visit,vector<vector<vector<long long>>>&dp){
        
        if(startRow>=m || startColumn>=n ||startColumn<0 ||startRow<0)return 1;
        if(maxMove<=move)return 0;
        if(dp[startRow][startColumn][move]!=-1)return dp[startRow][startColumn][move];
        if(visit[startRow][startColumn]<=maxMove){
            visit[startRow][startColumn]++;
            long long d,u,r,l;
            d=func(m,n,move+1,maxMove,startRow+1,startColumn,visit,dp);
            u=func(m,n,move+1,maxMove,startRow-1,startColumn,visit,dp);
            r=func(m,n,move+1,maxMove,startRow,startColumn+1,visit,dp);
            l=func(m,n,move+1,maxMove,startRow,startColumn-1,visit,dp);
            visit[startRow][startColumn]--;
            return dp[startRow][startColumn][move]=(d+l+r+u)%mod;
        }
        return 0;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<int>>visit(m,vector<int>(n,0));
        vector<vector<vector<long long>>>dp(m,vector<vector<long long>>(n,vector<long long>(maxMove,-1)));
        return func(m,n,0,maxMove,startRow,startColumn,visit,dp);
    }
};