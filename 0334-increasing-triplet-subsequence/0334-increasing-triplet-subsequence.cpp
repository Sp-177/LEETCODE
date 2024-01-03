class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int>ans;
        ans.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin()>=ans.size())ans.push_back(nums[i]);
            else {
               
                ans[lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin()]=nums[i];
            }
        }
        return ans.size()>=3;
    }
};