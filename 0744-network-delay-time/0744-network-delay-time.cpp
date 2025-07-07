class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>dp(n+1,INT_MAX);
        dp[0]=0;
        unordered_map<int,vector<pair<int,int>>>adj;
        for(auto i:times){
            int u=i[0],v=i[1],t=i[2];
            adj[u].push_back({v,t});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int time=it.first;
            int node=it.second;
            if(dp[node]<=time)continue;
            dp[node]=time;
            // cout<<node<<" "<<time<<endl;
            for(auto i:adj[node]){
                int nt=time+i.second;
                int child=i.first;
                if(dp[child]>nt){
                    pq.push({nt,child});
                }
            }
        }
        int maxi=*max_element(dp.begin(),dp.end());
        return (maxi==INT_MAX?-1:maxi);
    }
};