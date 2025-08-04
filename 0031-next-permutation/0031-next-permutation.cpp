class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int i=-1;
        bool swapped=false;
        for(i=n-1;i>=1;i--){
            if(nums[i-1]<nums[i]){
                int mini=i;
                for(int j=i;j<n;j++)if(nums[j]>nums[i-1]&&nums[j]<nums[mini])mini=j;
                swap(nums[i-1],nums[mini]);
                sort(nums.begin()+i,nums.end());
                swapped=true;
                break;
            }
        }
        if(!swapped)sort(nums.begin(),nums.end());
    }
};