class Solution {
public:
    int maxProfit(vector<int>& prices) {
    int i=0,j=1;
    long ans=0;
    while(j<prices.size()){
        if(prices[i]<prices[j]){ans+=prices[j]-prices[i];i=j;}
        else i=j; 
        j++;
    }
    return ans;
    }
};