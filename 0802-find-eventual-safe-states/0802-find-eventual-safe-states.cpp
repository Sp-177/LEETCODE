class Solution {
public:
    vector<int>topo(unordered_map<int,vector<int>>&m,vector<int>&indegree,int n){
        queue<int>q;
        for(int i=0;i<n;i++)if(indegree[i]==0)q.push(i);
        vector<int>ans;
        while(!q.empty()){
            int f=q.front();
            ans.push_back(f);
            q.pop();
            if(m.find(f)!=m.end())for(int i:m[f]){indegree[i]--;if(indegree[i]==0)q.push(i);}
        }
        return ans;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        unordered_map<int,vector<int>>m;
        vector<int>indegree(graph.size());
        for(int i=0;i<graph.size();i++){
            for(int j:graph[i])m[j].push_back(i);
            indegree[i]=graph[i].size();
        }
        vector<int>ans=topo(m,indegree,graph.size());
        sort(ans.begin(),ans.end());
        return ans;
    }
};