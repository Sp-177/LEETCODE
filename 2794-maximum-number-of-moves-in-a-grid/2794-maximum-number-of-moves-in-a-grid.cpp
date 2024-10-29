class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>v(n,vector<int>(m,-1));
        for(int i=0;i<n;i++)v[i][0]=0;
        for(int j=0;j<m-1;j++){
            for(int i=0;i<n;i++){
                if(v[i][j]>=0){
                if(i-1>=0){
                    if(grid[i][j]<grid[i-1][j+1])v[i-1][j+1]=v[i][j]+1;
                }
                if(i+1<n){
                    if(grid[i][j]<grid[i+1][j+1])v[i+1][j+1]=v[i][j]+1;
                }
                if(grid[i][j]<grid[i][j+1])v[i][j+1]=v[i][j]+1;
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++){
                ans=max(ans,v[i][j]);
            }
        }
        return ans;
    }
};