class Solution {
public:
    class DSU{
        public:
        vector<int>par,size;
        DSU(int n){
            par.resize(n);
            iota(par.begin(),par.end(),0);
            size.resize(n,0);
        }
        int find(int n){
            if(n==par[n])return n;
            return par[n]=find(par[n]);
        }
        void merge(int n,int m){
            int p1=find(n),p2=find(m);
            if(p1!=p2){
                if(size[p1]>=size[p2]){
                    size[p1]++;
                    par[p2]=par[m]=p1;
                }
                else{
                     size[p2]++;
                    par[p1]=par[n]=p2;
                }
            }
        }
    };
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<pair<int,vector<int>>,vector<pair<int,vector<int>>>,greater<pair<int,vector<int>>>>pq;
        int n=points.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int x1=points[i][0],y1=points[i][1];
                int x2=points[j][0],y2=points[j][1];
                int dist=abs(x2-x1)+abs(y2-y1);
                pq.push({dist,{i,j}});
            }
        }
        DSU obj(n);
        int ans=0;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int n1=it.second[0],n2=it.second[1];
            if(obj.find(n1)!=obj.find(n2)){
                obj.merge(n1,n2);
                ans+=it.first;
            }
        }
        return ans;
    }
};