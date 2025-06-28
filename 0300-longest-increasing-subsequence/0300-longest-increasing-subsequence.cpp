class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>arr;
        arr.push_back(nums[0]);
        for(int i=1;i<n;i++){

            int num=nums[i];
            auto it=lower_bound(arr.begin(),arr.end(),num);
            if(it==arr.end())arr.push_back(num);
            else{
                arr[it-arr.begin()]=num;
            }
        }
        return arr.size();
    }
};