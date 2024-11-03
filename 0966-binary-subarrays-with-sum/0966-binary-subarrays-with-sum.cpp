class Solution {
public:
int sol(vector<int>&nums,int k){
    if(k<0)return 0;
    int n=nums.size();
        int sum=0;
        int ans=0;
        int l=0,r=0;
        while(r<n){
           sum+=(nums[r]%2);
            while(sum>k){
                sum-=(nums[l]%2);
                l++;
            }
             ans+=(r-l+1);
            r++;
        }
        return ans;
}
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return sol(nums,goal)-sol(nums,goal-1);       
    }
};