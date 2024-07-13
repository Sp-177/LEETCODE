class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<vector<int>>q;
        for(int i=0;i<grid.size();i++){for(int j=0;j<grid[0].size();j++){if(grid[i][j]==2)q.push({i,j,0});}}
        int ans=0;
        int n=grid.size(),m=grid[0].size();
        while(!q.empty()){
            int x=q.front()[0];
            int y=q.front()[1];
            int t=q.front()[2];
            q.pop();
            ans=max(ans,t);
            if(x+1<n&&grid[x+1][y]==1){
                grid[x+1][y]=2;
                q.push({x+1,y,t+1});
            }
            if(x-1>=0&&grid[x-1][y]==1){
                grid[x-1][y]=2;
                q.push({x-1,y,t+1});
            }
            if(y+1<m&&grid[x][y+1]==1){
                grid[x][y+1]=2;
                q.push({x,y+1,t+1});
            }
            if(y-1>=0&&grid[x][y-1]==1){
                grid[x][y-1]=2;
                q.push({x,y-1,t+1});
            }
        }
         for(int i=0;i<grid.size();i++){for(int j=0;j<grid[0].size();j++){if(grid[i][j]==1){return -1;}}}
        return ans;
    }
};