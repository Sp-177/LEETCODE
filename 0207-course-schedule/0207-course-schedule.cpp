class Solution {
public:
    int topo(int n,unordered_map<int,vector<int>>&m, vector<int>&indegree){
       
        queue<int>q;
        for(int i=0;i<n;i++)if(indegree[i]==0)q.push(i);
        vector<int>ans;
        while(!q.empty()){
            int f=q.front();
            q.pop();
            if(m.find(f)!=m.end())for(int i:m[f]){indegree[i]--;if(indegree[i]==0)q.push(i);}
            ans.push_back(f);
        }
        return ans.size();
    }
    bool canFinish(int n, vector<vector<int>>& p) {
        unordered_map<int,vector<int>>m;
        vector<int>indegree(n);
        for(auto i:p){
            m[i[1]].push_back(i[0]);
            indegree[i[0]]++;
        }
        return n==topo(n,m,indegree);
    }
};