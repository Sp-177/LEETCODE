class tri{
    public:
    int s;int e;int p;
};
class Solution {
public:
    int func(vector<int>& startTime, vector<int>& endTime, vector<int>& profit,int last_i,vector<int>&dp){
    if(last_i>=startTime.size())return 0;
    if(dp[last_i]!=-1)return dp[last_i];
    int t=profit[last_i]+func(startTime,endTime,profit,(lower_bound(startTime.begin(),startTime.end(),endTime[last_i])-startTime.begin()),dp);
    int n_t=func(startTime,endTime,profit,last_i+1,dp);
    return dp[last_i]=max(t,n_t);
}
    static bool cmp(tri&a,tri&b){
        if(a.s<b.s)return true;
        else if(a.s==b.s){
            if(a.e<b.e)return true;
            else if(a.e==b.e){
                return a.p>b.p;
            }
        }
        return false;

    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<int>dp(startTime.size()+1,-1);
        vector<tri>v(startTime.size());
        for(int i=0;i<startTime.size();i++){
            v[i].s=startTime[i];
            v[i].e=endTime[i];
            v[i].p=profit[i];
        }
        sort(v.begin(),v.end(),cmp);
        for(int i=0;i<startTime.size();i++){
            startTime[i]=v[i].s;
            endTime[i]=v[i].e;
            profit[i]=v[i].p;
        }
        
        return func(startTime,endTime,profit,0,dp);
    }
};