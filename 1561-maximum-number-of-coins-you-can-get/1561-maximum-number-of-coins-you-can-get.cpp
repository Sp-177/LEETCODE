class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        int ans=0;
        int i=0;
        int j=piles.size()-1;
        int k=j-1;
        while(i+1<j){
            ans+=piles[k];
            i++;
            j-=2;
            k=j-1;
        }
        return ans;
    }
};