class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int rank=0;
        int ans=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]!=nums[i]){rank++;}
            ans+=rank;
        }
        return ans;
    }
};