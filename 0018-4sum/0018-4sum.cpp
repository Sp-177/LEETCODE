class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        set<vector<int>>s;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int start=j+1,end=n-1;
                while(start<end){
                    long long sum=1LL*nums[start]+1LL*nums[end]+1LL*nums[i]+1LL*nums[j];
                    if(sum==target){
                        s.insert({nums[start],nums[end],nums[i],nums[j]});
                        start++;end--;
                    }
                    else if(sum>target){end--;}
                    else {start++;}
                }
            }
        }
        for(auto i:s){ans.push_back(i);}
        return ans;
    }
};