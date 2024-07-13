class Solution {
public:
    int numEnclaves(vector<vector<int>>& board) {
        queue<vector<int>>q;
        int n=board.size(),m=board[0].size();
        // for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<board[i][j]<<' ';}cout<<endl;}
        for(int i=0;i<n;i++){if(board[i][0]==1){q.push({i,0});board[i][0]=-1;}
        if(board[i][m-1]==1){q.push({i,m-1});board[i][m-1]=-1;}}
        for(int i=0;i<m;i++){if(board[0][i]==1){q.push({0,i});board[0][i]=-1;}
        if(board[n-1][i]==1){q.push({n-1,i});board[n-1][i]=-1;}}
        // for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<board[i][j]<< ;}cout<<endl;}

        while(!q.empty()){
             int x=q.front()[0];
            int y=q.front()[1];
            q.pop();
            if(x+1<n&&board[x+1][y]==1){
                board[x+1][y]=-1;
                q.push({x+1,y});
            }
            if(x-1>=0&&board[x-1][y]==1){
                board[x-1][y]=-1;
                q.push({x-1,y});
            }if(y+1<m&&board[x][y+1]==1){
                board[x][y+1]=-1;
                q.push({x,y+1});
            }if(y-1>=0&&board[x][y-1]==1){
                board[x][y-1]=-1;
                q.push({x,y-1});
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
            if(board[i][j]==1){ans++;}
            
        }
        }
        
        return ans;
        // for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<board[i][j]<< ;}cout<<endl;}
    }
};