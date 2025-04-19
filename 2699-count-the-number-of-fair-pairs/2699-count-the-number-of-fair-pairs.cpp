#define ll long long
class Solution {
public:
    long long countFairPairs(vector<int >& nums, ll  lower, ll  upper) {
        long long ans=0;
        sort(nums.begin(),nums.end());
        ll  start=0,end=nums.size()-1;
        while(start<end){
            if(nums[start]+nums[end]>upper){
                end--;
            }
            else if(nums[start]+nums[end]<lower){
                start++;
            }
            else{
                auto it=lower_bound(nums.begin(),nums.end(),lower-nums[start]);
                if(it!=nums.end()){ans+=1+end-max((ll)(it-nums.begin()),start+1);
                // cout<<*it<<endl;
                // cout<<start<<" "<<end<<" "<<(it-nums.begin())<<endl;
                }
                start++;
            }
        }
        return ans;
    }
};