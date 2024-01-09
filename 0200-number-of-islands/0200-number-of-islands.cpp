class Solution {
public:
    void dfs(vector<vector<char>>& grid,  vector<vector<bool>>&visit,int m,int n,int i,int j){
        if(i<0 || j<0 ||i>=m||j>=n)return;
        if(grid[i][j]=='0' ||visit[i][j])return;
        visit[i][j]=true;
        dfs(grid,visit,m,n,i+1,j);
        dfs(grid,visit,m,n,i,j+1);
        dfs(grid,visit,m,n,i,j-1);
        dfs(grid,visit,m,n,i-1,j);
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        vector<vector<bool>>visit(grid.size(),vector<bool>(grid[0].size()));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]=='1'&&!visit[i][j]){
                    ans++;
                    dfs(grid,visit,grid.size(),grid[i].size(),i,j);
                }
            }
        }
        return ans;
    }
};