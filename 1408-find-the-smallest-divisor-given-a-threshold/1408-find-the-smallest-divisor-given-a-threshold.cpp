class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1,high=1e6;
        auto predicate=[&](int div)->bool{
            int sum=0;
            for(int i:nums)sum+=(i+div-1)/div;
            return sum<=threshold;
        };
        while(low<=high){
            int mid=(low+high)/2;
            if(predicate(mid))high=mid-1;
            else low=mid+1;
        }
        return low;

    }
};