class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        int n=grid.size(),m=grid[0].size();
        if(grid[0][0]!=0||grid[n-1][m-1]!=0){return -1;}
        pq.push({1,0,0});
        vector<vector<int>>dis(n,vector<int>(m,INT_MAX));
        dis[0][0]=1;
        while(!pq.empty()){
            int d=pq.top()[0];
            int x=pq.top()[1];
            int y=pq.top()[2];
            if(x==n-1&&y==m-1){return d;}
            pq.pop();
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                   
                    if(i==0&&j==0){continue;}
                    int x1=x+i,y1=y+j;
                    if(x1>=0&&x1<n&&y1>=0&&y1<m&&grid[x1][y1]==0&&dis[x1][y1]>d+1){
                        if(x1==n-1&&y1==m-1){return d+1;}
                        // cout<<x1<<y1<<endl;
                        dis[x1][y1]=d+1;
                        pq.push({d+1,x1,y1});
                    }
                }
            }

        }
        return -1;
    }
};