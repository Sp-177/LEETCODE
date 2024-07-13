class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& grid) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>dis(n,vector<int>(m,INT_MAX));
        dis[0][0]=0;
        pq.push({0,0,0});
        while(!pq.empty()){
            int d=pq.top()[0];
            int x=pq.top()[1];
            int y=pq.top()[2];
            if(x==n-1&&y==m-1){return d;}
            pq.pop();
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                   
                    if(abs(i)==abs(j)){continue;}
                    int x1=x+i,y1=y+j;
                    if(x1>=0&&x1<n&&y1>=0&&y1<m&&dis[x1][y1]>max(d,abs(grid[x][y]-grid[x1][y1]))){
                        dis[x1][y1]=max(d,abs(grid[x][y]-grid[x1][y1]));
                        pq.push({dis[x1][y1],x1,y1});
                    }
                }
            }
        }
        return 0;
    }
};