class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
    long long ans=nums[0];
    long long sum=0;
    
    for(int i=0;i<nums.size();i++){
        
        sum+=nums[i];
        ans=max(ans,sum);
        if(sum<0)sum=0;
        
        
    }
    return ans;
    }
};