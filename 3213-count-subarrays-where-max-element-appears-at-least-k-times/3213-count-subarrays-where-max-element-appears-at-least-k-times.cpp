#define ll long long
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        ll n=nums.size();
        // reverse(nums.begin(),nums.end());
        vector<ll>ss(n,0);
        ll maxi=*max_element(nums.begin(),nums.end());
        ll cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]==maxi)cnt++;
            ss[i]=cnt;
            // cout<<ss[i]<<" ";
        }
        ll ans=0;
        for(int i=0;i<n;i++){
            
                int fq=k+ss[i]+((nums[i]==maxi)?-1:0);
                auto it=lower_bound(ss.begin(),ss.end(),fq);
                if(it!=ss.end()){
                    // cout<<it-ss.begin()<<" "<<n-(it-ss.begin())+1<<endl;
                    ans+=n-(it-ss.begin());
                }
            
        }
        return ans;
    }
};