class tri{
    public:
        int i;
        int j;
        int t;
};
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ans=0;
        queue<tri>q;
        vector<vector<bool>>visit(grid.size(),vector<bool>(grid[0].size()));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==2){
                    tri T;
                    T.i=i;
                    T.j=j;
                    T.t=0;
                    q.push(T);
                    visit[i][j]=true;
                }
                else if(grid[i][j]==0)visit[i][j]=true;
            }
        }
        while(!q.empty()){
            tri x=q.front();
            q.pop();
            if(x.i+1<grid.size() && !visit[x.i+1][x.j] && grid[x.i+1][x.j]==1){
                visit[x.i+1][x.j]=true;
                tri y;
                y.i=x.i+1;
                y.j=x.j;
                y.t=x.t+1;
                grid[x.i+1][x.j]=2;
                q.push(y);
                ans=max(ans,y.t);
            }
            if(x.i-1>=0&& !visit[x.i-1][x.j] && grid[x.i-1][x.j]==1){
                  visit[x.i-1][x.j]=true;
                tri y;
                y.i=x.i-1;
                y.j=x.j;
                y.t=x.t+1;
                grid[x.i-1][x.j]=2;
                q.push(y);
                ans=max(ans,y.t);
            }
             if(x.j+1<grid[0].size()&& !visit[x.i][x.j+1] && grid[x.i][x.j+1]==1){  
                 visit[x.i][x.j+1]=true;
                tri y;
                y.i=x.i;
                y.j=x.j+1;
                y.t=x.t+1;
                grid[x.i][x.j+1]=2;
                q.push(y);
                ans=max(ans,y.t);
                    
                }
            if(x.j-1>=0&& !visit[x.i][x.j-1] && grid[x.i][x.j-1]==1){
                  visit[x.i][x.j-1]=true;
                tri y;
                y.i=x.i;
                y.j=x.j-1;
                y.t=x.t+1;
                grid[x.i][x.j-1]=2;
                q.push(y);
                ans=max(ans,y.t);
                }
        }
    for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(!visit[i][j])return -1;
            }
        }
        return ans;
    }
};