class Solution {
public:
    int candy(vector<int>& rat) {
        int ans=rat.size(),n=ans;
        vector<int>candy(n,1);
        vector<pair<int,int>>rat_ind(n);
        for(int i=0;i<n;i++){
            rat_ind[i]={rat[i],i};
        }
        sort(rat_ind.begin(),rat_ind.end());
        
        for(int i=0;i<n;i++){
            int ind=rat_ind[i].second;
            if(ind-1>=0&& rat[ind-1]>rat[ind]&&candy[ind-1]<=candy[ind]){
                 ans+=candy[ind]-candy[ind-1]+1;
                candy[ind-1]=candy[ind]+1;
            }
            if(ind+1<n&& rat[ind+1]>rat[ind]&&candy[ind+1]<=candy[ind]){
                ans+=candy[ind]-candy[ind+1]+1;
                candy[ind+1]=candy[ind]+1;
                
            }
        }
        return ans;
    }
};