class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
    long long ans=nums[0];
    long long sum=0;
    
    for(int i=0;i<nums.size();i++){
            if(sum<0)sum=0;
            sum=(sum+nums[i]);
            
            if(ans<sum ||ans<nums[i]){
                if(sum<nums[i])ans=nums[i];
                else ans=sum;
            }
        
    }
    return ans;
    }
};