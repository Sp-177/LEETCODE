class Solution {
public:
    void solve(int i,vector<vector<int>>&ans,vector<int>&nums,vector<int>&output){
        ans.push_back(output);
        for(int j=i;j<nums.size();j++){
            if(j>i && nums[j-1]==nums[j])continue;
            
            output.push_back(nums[j]);
            solve(j+1,ans,nums,output);

            output.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>output;
        solve(0,ans,nums,output);
        return ans;
    }
};