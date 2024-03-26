class Solution {
public:
    bool check(int i,int j,vector<string>&grid){
        for(int k=0;k<grid.size();k++){
            if(grid[i][k]=='Q'||grid[k][j]=='Q')return false;
        }
        for(int k=i,l=j;k<grid.size()&&l<grid.size();k++,l++){
        if(grid[k][l]=='Q')return false;
        }
        for(int k=i,l=j;k>=0&&l>=0;k--,l--){
        if(grid[k][l]=='Q')return false;
        }
        for(int k=i,l=j;k<grid.size()&&l>=0;k++,l--){
        if(grid[k][l]=='Q')return false;
        }
        for(int k=i,l=j;k>=0&&l<grid.size();k--,l++){
        if(grid[k][l]=='Q')return false;
        }
        return true;
    }
    void sol(int i,vector<string>&grid,vector<vector<string>>&ans){
        if(i==grid.size()){
            ans.push_back(grid);
            return;
        }
        for(int k=0;k<grid.size();k++){
            if(check(i,k,grid)){
                grid[i][k]='Q';
                sol(i+1,grid,ans);
                grid[i][k]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        string s="";
        for(int i=0;i<n;i++)s+=".";
        vector<string>grid(n,s);
        vector<vector<string>>ans;
        sol(0,grid,ans);
        return ans;
    }
    };