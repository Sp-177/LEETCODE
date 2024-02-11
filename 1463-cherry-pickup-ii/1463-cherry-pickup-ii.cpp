class Solution {
public:
    int sol(vector<vector<int>>&grid,int i,int j,int k,vector<vector<vector<int>>>&dp){
        if(i<0 ||j<0 ||i>=grid.size() ||j>=grid[0].size() ||k>=grid[0].size() ||k<0||j==k)return 0;
        if(i==grid.size()-1 && j>=0 &&j<=grid[0].size()-1 &&k>=0 &&k<=grid[0].size()-1){
            return grid[i][j]+grid[i][k];
        }
        if(dp[i][j][k]!=-1)return dp[i][j][k];
        int a[]={-1,0,1};
        int sum=grid[i][j]+grid[i][k];
        int ans=0;
        for(int l=0;l<3;l++){
            for(int m=0;m<3;m++){
                ans=max(ans,sol(grid,i+1,j+a[l],k+a[m],dp)+sum);
            }
        }
        return dp[i][j][k]=ans;

    }
    int cherryPickup(vector<vector<int>>& grid) {
        vector<vector<vector<int>>>dp(grid.size(),vector<vector<int>>(grid[0].size(),vector<int>(grid[0].size(),-1)));
        
        return sol(grid,0,0,grid[0].size()-1,dp);
    }
};
