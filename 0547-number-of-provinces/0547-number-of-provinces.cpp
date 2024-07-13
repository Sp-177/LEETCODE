class Solution {
public:
    void dfs(int node,vector<bool>&visit,vector<vector<int>>& isC){
        visit[node]=1;
        for(int i=0;i<isC[node].size();i++){
            if(isC[node][i]&&visit[i]==0){
                dfs(i,visit,isC);
            }
        }

    }
    int findCircleNum(vector<vector<int>>& isC) {
        vector<bool>visit(isC.size(),0);
        int ans=0;
        for(int i=0;i<isC.size();i++){
            if(visit[i]==0){
                dfs(i,visit,isC);
                ans++;
            }
        }
        return ans;

    }
};