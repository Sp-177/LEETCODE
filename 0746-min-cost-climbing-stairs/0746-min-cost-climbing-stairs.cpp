class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>copy=cost;
        int n=cost.size()-1;
        for(int i=1,j=2;i<=n,j<=n+1;i++,j++){
            int x=cost[i-1],y=INT_MAX;
            if(i-2>=0){
                y=cost[i-2];
            }
            cost[i]+=min(x,y);
            if(j<=n){
            int a=copy[j-1],b=INT_MAX;
            if(j-2>=1){
                b=copy[j-2];
            }
            copy[j]+=min(a,b);
            }
        }
        int a=min(cost[n],cost[n-1]);
        cost.clear();
        int b=min(copy[n],copy[n-1]);
        copy.clear();
        return min(a,b);
    }
};