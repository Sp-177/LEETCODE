class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
       int size=0;
        sort(nums.begin(),nums.end());
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++){m[nums[i]]++;size=max(size,m[nums[i]]);}
        vector<vector<int>>ans(size);
        for(int i=1;i<=nums.size();i=i+m[nums[i-1]]){
            for(int j=1;j<=m[nums[i-1]];j++){
                ans[j-1].push_back(nums[i-1]);
            }
        }
        return ans;
    }
};