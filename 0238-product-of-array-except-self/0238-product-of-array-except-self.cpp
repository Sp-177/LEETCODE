class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<long long>left(nums.size()),right(nums.size());
        vector<int>ans(nums.size());
        int r=nums.size()-1;
        left[0]=nums[0];
        right[r]=nums[r];
        for(int i=1;i<nums.size();i++){
            left[i]=left[i-1]*nums[i];
            r--;
            right[r]=right[r+1]*nums[r];
        }
        for(int i=0;i<nums.size();i++){
            ans[i]=1;
            if(i-1>=0){
                ans[i]=left[i-1];
            }
            if(i+1<nums.size()){
                ans[i]*=right[i+1];
            }
        }
        return ans;
    }
};