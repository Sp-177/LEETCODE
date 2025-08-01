class Solution {
public:
    int candy(vector<int>& rat) {
        int n=rat.size();
        vector<int>candy(n,1);
        for(int i=0;i<n-1;i++){
            if(rat[i]<rat[i+1]){
                candy[i+1]=candy[i]+1;
            }
        }
        for(int i=n-1;i>=1;i--){
            if(rat[i-1]>rat[i]){
                candy[i-1]=max(candy[i-1],candy[i]+1);
            }
        }
        int ans=accumulate(candy.begin(),candy.end(),0);
        return ans;
    }
};