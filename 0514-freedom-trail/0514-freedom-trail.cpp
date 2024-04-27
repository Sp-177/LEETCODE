class Solution {
public:
    int sol(string ring ,string key,int index_key,int index_ring,unordered_map<char,vector<int>>&m,vector<vector<int>>&dp){
        if(index_key==key.size())return 0;
        if(index_ring==-1)index_ring=ring.size()-1;
        if(index_ring==ring.size())index_ring=0;
        if(dp[index_ring][index_key]!=-1)return dp[index_ring][index_key];
        vector<int>c=m[key[index_key]];
        int ans=INT_MAX;
        for(int i:c){
            int dist1=abs(index_ring-i);
            int dist2=min(index_ring,i)+ring.size()-max(index_ring,i);
            int dis=min(dist1,dist2);
            
            ans=min(sol(ring,key,index_key+1,i,m,dp)+1+dis,ans);
        }
       
        return dp[index_ring][index_key]=ans;
    }
    int findRotateSteps(string ring, string key) {
        unordered_map<char,vector<int>>m;
        vector<vector<int>>dp(ring.size(),vector<int>(key.size(),-1));
        for(int i=0;i<ring.size();i++)m[ring[i]].push_back(i);
        return sol(ring,key,0,0,m,dp);
        
    }
};