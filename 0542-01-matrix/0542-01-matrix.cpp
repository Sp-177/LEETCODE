class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>ans(n,vector<int>(m));
        vector<vector<bool>>visit(n,vector<bool>(m));
        queue<vector<int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)if(mat[i][j]==0){q.push({i,j,0});visit[i][j]=true;}
        }
        while(!q.empty()){
            vector<int>top=q.front();
            int i=top[0],j=top[1],v=top[2];
            ans[i][j]=v;
            if(i-1>=0 && visit[i-1][j]!=true){
                visit[i-1][j]=true;
                q.push({i-1,j,v+1});
            }
            if(i+1<n && visit[i+1][j]!=true){
                visit[i+1][j]=true;
                q.push({i+1,j,v+1});
            }
            if(j-1>=0 && visit[i][j-1]!=true){
                visit[i][j-1]=true;
                q.push({i,j-1,v+1});
            }
            if(j+1<m && visit[i][j+1]!=true){
                visit[i][j+1]=true;
                q.push({i,j+1,v+1});
            }
            q.pop();
        }
        return ans;
    }
};