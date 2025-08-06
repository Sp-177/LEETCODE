class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int low=*max_element(nums.begin(),nums.end()),high=accumulate(nums.begin(),nums.end(),0);
        auto p=[&](int sum)->bool{
            int cnt=1;
            int add=0;
            for(int i:nums){
                if(add+i<=sum){
                    add+=i;
                }
                else{
                    add=i;
                    cnt++;
                }
            }
            return cnt<=k;
        };
        while(low<=high){
            int mid=(low+high)>>1;
            if(p(mid))high=mid-1;
            else low=mid+1;
        }
        return low;

    }
};