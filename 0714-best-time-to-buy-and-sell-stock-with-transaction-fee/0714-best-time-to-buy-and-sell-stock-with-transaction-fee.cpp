class Solution {
public:
    int F;
    vector<vector<int>>dp;
    int func(vector<int>&prices,int n,int index,int mode){
        if(index>=n)return 0;
        if(dp[index][mode]!=-1)return dp[index][mode];
        if(mode==1){
            return dp[index][mode]=max(func(prices,n,index+1,mode^1)-prices[index],func(prices,n,index+1,mode));
        }
        return dp[index][mode]=max(func(prices,n,index+1,mode^1)+prices[index]-F,func(prices,n,index+1,mode));

    } 
    int maxProfit(vector<int>& prices, int fee) {
        F=fee;
        int n=prices.size();
        dp.resize(n,vector<int>(2,-1));
        return func(prices,n,0,1);
    }
};