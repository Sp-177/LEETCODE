class Solution {
public:
    unordered_map<int,unordered_map<int,int>>dp;
    int func(int start,int end,vector<int>&cuts){
        // cout<<start<<" "<<end<<endl;
        if(start==end || end-start==1)return 0;
        if(dp.count(start) && dp[start].count(end))return dp[start][end];
        auto it=lower_bound(cuts.begin(),cuts.end(),start+1);
        int sum=INT_MAX;
        if(it!=cuts.end()){
            int ind=it-cuts.begin();
            // cout<<ind<<endl;
            for(int i=ind;i<cuts.size();i++){
                int num=cuts[i];
                if(end>num){
                    int a1=func(start,num,cuts);
                    int a2=func(num,end,cuts);
                    if(a1!=INT_MAX&& a2!=INT_MAX){
                        sum=min(sum,end-start+a1+a2);
                    }
                }
                else break;
            }
        }
        
        // cout<<sum<<endl;
        return dp[start][end]=((sum==INT_MAX)?0:sum);
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        return func(0,n,cuts);
    }
};