class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0,high=n-1;

        while(low<=high){
            int mid=(low+high)/2;
            int l=nums[low],r=nums[high],m=nums[mid];
            // cout<<l<<" "<<m<<" "<<r<<endl;
            if(m==target)return mid;
            if(l>m){
                if(target<m||target>=l)high=mid-1;
                else low=mid+1;

            }
            else {
               if(target<m&&target>=l)high=mid-1;
               else low=mid+1;
            }
        }
        return -1;
    }
};