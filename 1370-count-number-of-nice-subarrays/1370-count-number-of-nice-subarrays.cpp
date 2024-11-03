class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>m;
        m[0]++;
        int sum=0;
        int ans=0;
    
        for(int i=0;i<n;i++){
            sum+=nums[i]%2;
            ans+=m[sum-k];
            m[sum]++;
        }
        return ans;
    }
};