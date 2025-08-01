class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,INT_MAX-1);
        ans[n-1]=0;
        for(int i=n-2;i>=0;i--){
            for(int j=1;j<=i+nums[i]&&j<n;j++){
                ans[i]=min(ans[i],ans[j]+1);
            }
            
        }
        return ans[0];

    }
};