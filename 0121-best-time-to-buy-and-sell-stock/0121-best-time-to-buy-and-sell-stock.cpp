class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        int sell=prices[prices.size()-1];
        for(int i=prices.size()-2;i>=0;i--){
            ans=max(ans,sell-prices[i]);
            if(sell<prices[i]){
                sell=prices[i];
            }
        }
        return ans;
    }
};