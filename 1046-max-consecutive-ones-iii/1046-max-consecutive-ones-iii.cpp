class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0,j=0,K=k,ans=0,n=nums.size();
        while(i<n&&j<n){
            // cout<<i<<' '<<j<<endl;
            if(nums[j]==0){
                if(K){
                    K--;
                }
                else{
                    while(i<=j){
                        if(nums[i++]==0){break;}
                    }
                }
            }
            ans=max(j-i+1,ans);
            j++;
        }
        return ans;
    }
};