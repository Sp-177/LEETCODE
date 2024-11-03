class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int arr[n];
        for(int i=0;i<n;i++){if(nums[i]&1)arr[i]=1;else arr[i]=0;}
        map<int,int>m;
        m[0]++;
        int sum=0;
        int ans=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            ans+=m[sum-k];
            m[sum]++;
        }
        return ans;
    }
};