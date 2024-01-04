class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
    unordered_map<int,int>m;
    for(int i=0;i<nums.size();i++)m[i]=i;
    vector<int>dp(nums.size(),1);
    int s=1;int ind=0;
    for(int i=1;i<nums.size();i++){
        for(int j=0;j<i;j++){
            if((nums[i]%nums[j]==0 &&dp[i]<dp[j]+1)){
                dp[i]=dp[j]+1;
                m[i]=j;
            }
        }
        if(s<dp[i]){s=dp[i];ind=i;}
    }
    vector<int>ans;
    while(m[ind]!=ind){
        ans.push_back(nums[ind]);
        ind=m[ind];
    }
    
    ans.push_back(nums[ind]);
    return ans;
    }
};