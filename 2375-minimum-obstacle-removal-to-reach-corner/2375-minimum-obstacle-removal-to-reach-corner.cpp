class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        priority_queue<pair<int,vector<int>>,vector<pair<int,vector<int>>>,greater<pair<int,vector<int>>>>pq;
        vector<vector<int>>visited(n,vector<int>(m,0)),dist(n,vector<int>(m,INT_MAX));
        pq.push({0,{0,0}});
        vector<vector<int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
        dist[0][0]=grid[0][0]!=0?1:0;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int ans=it.first;
            int x=it.second[0],y=it.second[1];
            // cout<<ans<<" "<<x<<" "<<y<<endl;
            if(visited[x][y])continue;
            visited[x][y]=1;
            if(x==n-1&&y==m-1)return ans;
            for(auto d:dir){
                int x1=x+d[0],y1=y+d[1];
                if(x1>=0 && x1<n&&y1>=0 &&y1<m){
                    int extra=(grid[x1][y1]!=0?1:0);
                    if(dist[x1][y1]>ans+extra){
                        dist[x1][y1]=ans+extra;
                        pq.push({ans+extra,{x1,y1}});
                    }
                }
            }

        }
        return 0;

    }
};