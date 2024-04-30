class Solution {
public:
    void dfs(vector<vector<char>>& board,int n,int m,int i,int j,vector<vector<bool>>&visit){
        if(i<0 ||j<0||i==n||j==m||visit[i][j]||board[i][j]=='X')return;
        visit[i][j]=true;
        dfs(board,n,m,i,j+1,visit);
        dfs(board,n,m,i-1,j,visit);
        dfs(board,n,m,i+1,j,visit);
        dfs(board,n,m,i,j-1,visit);
        
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<bool>>visit(n,vector<bool>(m));
        for(int i=0;i<n;i++){
            if(board[i][0]=='O' && !visit[i][0]){
                dfs(board,n,m,i,0,visit);
            }
            if(board[i][m-1]=='O' && !visit[i][m-1]){
                dfs(board,n,m,i,m-1,visit);
            }
            
        }
        for(int i=0;i<m;i++){
            if(board[0][i]=='O' && !visit[0][i]){
                dfs(board,n,m,0,i,visit);
            }
            if(board[n-1][i]=='O' && !visit[n-1][i]){
                dfs(board,n,m,n-1,i,visit);
            }
            
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)if(!visit[i][j])board[i][j]='X';
        }
    }
};