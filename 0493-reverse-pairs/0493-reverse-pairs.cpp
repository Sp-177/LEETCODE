class Solution {
public:
    long long  divide(vector<int>&nums,long long  low,long long  high){
        if(high<=low)return 0;
        long long  mid=(low+high)/2;
        long long  a1=divide(nums,low,mid);
        long long  a2=divide(nums,mid+1,high);
        long long  a3=merge(nums,low,mid,high);
        // cout<<"A-"<<a1+a2+a3<<endl;
        return a1+a2+a3;
    }
    long long  merge(vector<int>&nums,long long  low,long long  mid,long long  high){
        // cout<<low<<' '<<mid<<' '<<high<<endl;
        sort(nums.begin()+low,nums.begin()+mid+1);
        // for(long long  i=0;i<=mid;i++)cout<<nums[i]<<" ";
        // cout<<endl;
        long long  ans=0;
        for(long long  i=mid+1;i<=high;i++){
            // cout<<nums[i]<<' ';
            long long  index=upper_bound(nums.begin()+low,nums.begin()+mid,2*1LL*nums[i])-nums.begin()-low;
            if(index+low<=mid&&nums[index+low]>2*1LL*nums[i]){
                ans+=(mid-index-low+1);
            }
        }
        // cout<<endl;
        return ans;
    }
    long long  reversePairs(vector<int>& nums) {
        return divide(nums,0,nums.size()-1);
    }
};