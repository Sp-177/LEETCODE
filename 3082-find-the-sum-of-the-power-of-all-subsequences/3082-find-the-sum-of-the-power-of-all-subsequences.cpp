class Solution {
public:
    long long mod=1e9+7;
    long long power(long long a,long long b){
        long long res = 1;
        while(b){
            if(b&1) res = (res * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return res;
    }
    long long sol(vector<int>&nums,int k, vector<vector<vector<long long>>>&dp,int i,int count){
        if(k==0){long long ans=power(2,nums.size()-count);return ans%mod;}
        if(i<0)return 0;
        if(dp[i][k][count]!=-1)return dp[i][k][count];
        long long t=0,n_t=0;
        n_t=sol(nums,k,dp,i-1,count);
        if(nums[i]<=k)t=sol(nums,k-nums[i],dp,i-1,count+1);
        return dp[i][k][count]=(t+n_t)%mod;
    } 
    int sumOfPower(vector<int>& nums, int k) {
        
        vector<vector<vector<long long>>>dp(nums.size(),vector<vector<long long>>(k+1,vector<long long>(nums.size()+1,-1)));
        return (sol(nums,k,dp,nums.size()-1,0))%mod;
    }
};