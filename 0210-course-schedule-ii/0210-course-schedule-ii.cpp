class Solution {
public:
bool dfs(int node,vector<int>&ans,vector<bool>&visit, vector<vector<bool>>&adj,int n,vector<bool>&path){
    visit[node]=true;
    path[node]=true;
    for(int i=0;i<n;i++){
        if(adj[node][i]){
        if(i!=node && path[i]){
            return false;
        }
        if(i!=node && visit[i]==false )if(dfs(i,ans,visit,adj,n,path)==false)return false;}
    }
    path[node]=false;
    ans.push_back(node);
    return true;
}
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        vector<int>ans;
        vector<bool>visit(n),path(n);
    vector<vector<bool>>adj(n,vector<bool>(n));
    for(vector<int>i:p){
        adj[i[1]][i[0]]=true;
    }
        for(int i=0;i<n;i++){
            if(!visit[i]){
                if(dfs(i,ans,visit,adj,n,path)==false)return{};
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};