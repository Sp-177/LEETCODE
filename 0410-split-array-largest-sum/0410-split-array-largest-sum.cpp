class Solution {
public:
    int sol(vector<int>&nums,int sum){
        int cnt=1,part=0;
        for(int i:nums){
            // if(sum<i)return INT_MAX;
            if(part+i<=sum)part+=i;
            else{
                part=i;cnt++;
            }
        }
        return cnt;
    }
    int splitArray(vector<int>& nums, int k) {
        int low=INT_MIN,high=0;
        for(int i:nums){
            low=max(low,i);
            high+=i;
        }
        int ans=INT_MAX;
        while(low<=high){
            int mid=(low+high)/2;
            int cnt=sol(nums,mid);
            // cout<<cnt<<" "<<mid<<endl;
           
            if(cnt>k){
                low=mid+1;
            }
            else high=mid-1;
        }
        return low;
    }
};