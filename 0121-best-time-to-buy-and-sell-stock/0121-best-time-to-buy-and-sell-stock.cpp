class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        int maxi=prices[prices.size()-1];
        for(int i=prices.size()-1;i>=0;i--){
            ans=max(ans,maxi-prices[i]);
            maxi=max(maxi,prices[i]);
        }
        return ans;
    }
};