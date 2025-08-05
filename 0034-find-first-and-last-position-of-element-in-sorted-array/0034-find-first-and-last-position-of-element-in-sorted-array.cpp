class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        if(n==0)return {-1,-1};
        auto It=lower_bound(nums.begin(),nums.end(),target);
        if(It==nums.end() || (It!=nums.end()&& nums[It-nums.begin()]!=target))return {-1,-1};
        int startInd=It-nums.begin();
        int endInd=upper_bound(nums.begin(),nums.end(),target)-nums.begin() -1;
        return {startInd,endInd};

    }
};