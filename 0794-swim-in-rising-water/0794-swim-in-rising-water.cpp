class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>dp(n,vector<int>(n,INT_MAX));
        priority_queue<pair<int,vector<int>>,vector<pair<int,vector<int>>>,greater<pair<int,vector<int>>>>pq;
        pq.push({grid[0][0],{0,0}});
        int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
        while(!pq.empty()){
            
            auto it=pq.top();
            pq.pop();
            int time=it.first;
            int x=it.second[0];
            int y=it.second[1];
            // cout<<x<<" "<<y<<endl;
            if(x==n-1&&y==n-1)return time;
            if(dp[x][y]<=time)continue;
            dp[x][y]=time;
            for(auto i:dir){
                int x1=x+i[0],y1=y+i[1];
                if(x1>=0&&x1<n&&y1>=0&&y1<n && dp[x1][y1]>max(time,grid[x1][y1])){
                    pq.push({max(time,grid[x1][y1]),{x1,y1}});
                }
            }
        }
        return 0;
    }
};