class Solution {
    private:
    bool check(vector<vector<char>>& board,vector<vector<bool>>& grid,int i,int j,char c,int m,int n){
        if(i<0||j<0||i>=m||j>=n||grid[i][j]||board[i][j]!=c){
            return false;
        }
        return true;
    }
    bool func(vector<vector<char>>& board,vector<vector<bool>>& grid,string word,int i,int j,int x,int m,int n){
        
        if(x==word.size()){return true;}
        else if(i==m-1 && j==n){return false;}
        if(check(board,grid,i,j,word[x],m,n)){
            grid[i][j]=true;
            if(func(board,grid,word,i,j+1,x+1,m,n))return true;
            if(func(board,grid,word,i+1,j,x+1,m,n))return true;
            if(func(board,grid,word,i,j-1,x+1,m,n))return true;
            if(func(board,grid,word,i-1,j,x+1,m,n))return true;
            grid[i][j]=false;
        }
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>>grid(board.size(),vector<bool>(board[0].size(),0));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0]){
         if(func(board,grid,word,i,j,0,board.size(),board[0].size()))return true;}}}
         return false;
    }
};