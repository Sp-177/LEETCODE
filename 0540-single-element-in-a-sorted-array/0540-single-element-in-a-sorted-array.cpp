class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int low=0,high=n-1;
        while(low<=high){
            int mid=(low+high)>>1;
            int m=nums[mid];
            int i=-1;
            if(mid-1>=0&&nums[mid-1]==m)i=mid-1;
            else if(mid+1<n&&nums[mid+1]==m)i=mid+1;
            else return m;
            int left=min(i,mid);
            int right=max(i,mid);
            int l_len=left-low;
            if(l_len&1)high=left-1;
            else low=right+1;
        }
        return -1;
    }
};