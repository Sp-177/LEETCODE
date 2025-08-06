class Solution {
public:
    int func(int low,int high,vector<int>&nums){
        if(low>high)return INT_MAX;
        if(low==high)return nums[low];
        int mid=(low+high)>>1;
         int m=nums[mid];
        int l=nums[low],h=nums[high];
            if(l>m&&m>h){
                return func(mid+1,high,nums);
            }
            else if(l<m&&m<h){
                return func(low,mid-1,nums);
            }
            return min({func(low,mid-1,nums),func(mid+1,high,nums),m});
    }
    int findMin(vector<int>& nums) {
        int n=nums.size();
        return func(0,n-1,nums);
    }
};