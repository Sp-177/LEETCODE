class Solution {
public:
    int sol(vector<int>&nums,int k){
        if(k==0)return 0;
               int ans=0;
        map<int,int>m;
        int start=0,end=0;
        while(end<nums.size()){
            m[nums[end]]++;
            while(m.size()>k&&start<end){
                m[nums[start]]--;
                if(m[nums[start]]==0)m.erase(nums[start]);
                start++;
            }
            ans+=(end-start+1);
            end++;
        }
        return ans;
    } 
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return sol(nums,k)-sol(nums,k-1);
    }
};