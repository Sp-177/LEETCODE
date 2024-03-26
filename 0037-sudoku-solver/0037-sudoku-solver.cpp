class Solution {
public:
    bool check(vector<vector<char>>&board,int i,int j,char num){
        
        for(int k=0;k<9;k++){
            if(board[i][k]==num || board[k][j]==num)return false;
        }
        vector<int>a={0,3,6,9};
        int lx=0,ly=0;
        for(int k=1;k<4;k++){
            if(a[k-1]<=i&&a[k]>i)lx=a[k];
            if(a[k-1]<=j&&a[k]>j)ly=a[k];
        }
       
        for(int k=lx-3;k<lx;k++){
            for(int l=ly-3;l<ly;l++){
                if(board[k][l]==num)return false;
            }
        }
        return true;
    }
    bool sol(int i,int j,vector<vector<char>>&board){
          if(j==9){j=0;i++;}
        if(i==9)return true;
        if(board[i][j]!='.')return sol(i,j+1,board);
        bool say=false;
       
            for(int l=1;l<=9;l++){
            if(check(board,i,j,l+'0')){
                board[i][j]=char(l+'0');
                say=say||sol(i,j+1,board);
                if(say)return say;
            board[i][j]='.';}
            
            }
            
        
        return say;
    }
    void solveSudoku(vector<vector<char>>& board) {
        sol(0,0,board);
    }
};