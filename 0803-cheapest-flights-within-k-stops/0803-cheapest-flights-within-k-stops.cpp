class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        pq.push({0,0,src});
        map<int,map<int,int>>m;
        vector<int>costing(n,INT_MAX);
        costing[src]=0;
        for(auto i:flights){
            m[i[0]][i[1]]=i[2];
        }
        int ans=INT_MAX;
        while(!pq.empty()){
            int stop=pq.top()[0];
            int price=pq.top()[1];
            int node=pq.top()[2];
            pq.pop();
            if(stop<=k+1&&node==dst){ans=min(ans,price);}
            for(auto i:m[node]){
                int cost=price+i.second,n_s=i.first;
                if(costing[n_s]>cost){
                    costing[n_s]=cost;
                pq.push({stop+1,cost,n_s});
                }
            }
        }
        return (ans==INT_MAX?-1:ans);
    }
};