class Solution {
public:
    int Jump(vector<int>&nums,int index,vector<int>&dp){
        if(index>=nums.size()){return INT_MAX;}
        if(index==nums.size()-1){return 0;}
        if(dp[index]!=-1){return dp[index];}
        int ans=INT_MAX;
        for(int i=1;i<=nums[index];i++){
            if(index+i<nums.size()){
                int out=Jump(nums,index+i,dp);

                if(out!=INT_MAX)ans=min(ans,out+1);
            }
        }
        return dp[index]=ans;
    }
    int jump(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return Jump(nums,0,dp);
    }
};