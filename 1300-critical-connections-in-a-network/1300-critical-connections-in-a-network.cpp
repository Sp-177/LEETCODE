class Solution {
public:
    vector<vector<int>>ans;
    unordered_map<int,vector<int>>adj;
    vector<int>inTime,low;
    int dfs(int node,int par,int time){
        // cout<<node<<" "<<time<<endl;
        inTime[node]=low[node]=time;
        int newTime=time;
        for(auto child:adj[node]){
            if(child==par)continue;
            if(low[child]==INT_MAX){
                int t=dfs(child,node,newTime+1);
                newTime=t;
            }
            if(low[child]>inTime[node])ans.push_back({node,child});
            low[node]=min(low[node],low[child]);

        }
         
        return newTime;
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& c) {
        inTime.resize(n);
        low.resize(n,INT_MAX);
        for(auto &edge:c){
            int u=edge[0],v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(0,0,0);
        return ans;
    }
};