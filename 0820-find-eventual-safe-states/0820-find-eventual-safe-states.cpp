class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        map<int,vector<int>>adj;
        vector<int>indg(graph.size());
        for(int i=0;i<graph.size();i++){
            for(int j:graph[i]){
                adj[j].push_back(i);
            }
        }
        for(auto i:adj){
            for(int j:i.second){
                indg[j]++;
            }
        }
        queue<int>q;
        for(int i=0;i<graph.size();i++){
            if(indg[i]==0){
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty()){
            int node=q.front();
            ans.push_back(node);
            q.pop();
            for(int i:adj[node]){
                indg[i]--;
                if(indg[i]==0){q.push(i);}
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};