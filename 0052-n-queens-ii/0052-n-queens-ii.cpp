class Solution {
    private:
    int ans=0;
    bool check(int n,vector<vector<int>>&grid,int i,int j){
        for(int x=0;x<n;x++){
            if(grid[i][x]==1){return false;}
        }
        for(int x=0;x<n;x++){
            if(grid[x][j]==1){return false;}
        }
        for(int x=i,y=j;x<n&&y<n;x++,y++){
            if(grid[x][y]==1){return false;}
        }
        for(int x=i,y=j;x>=0&&y>=0;x--,y--){
            if(grid[x][y]==1){return false;}
        }
        for(int x=i,y=j;x<n&&y>=0;x++,y--){
            if(grid[x][y]==1){return false;}
        }
        for(int x=i,y=j;x>=0&&y<n;x--,y++){
            
            if(grid[x][y]==1){return false;}
        }
        return true;
    }
    void func(int n,vector<vector<int>>&grid,int i){
        if(i==n){ans++;return ;}
        for(int x=0;x<n;x++){
            if(check(n,grid,i,x)){
                grid[i][x]=1;
                func(n,grid,i+1);
                grid[i][x]=0;
            }
        }
    }
public:
    int totalNQueens(int n) {
        vector<vector<int>>grid(n,vector<int>(n,0));
        func(n,grid,0);
        return ans;
    }
};