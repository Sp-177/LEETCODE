#define ll long long
class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
     long long ans=0,n=nums.size();
        unordered_map<int,int>mp;
        auto add=[&](int index)->void{
            if(index<0)return;
            ans+=n-index;
        };
        ll cnt_pr=0;
        auto inc=[&](int index)->void{
            int num=nums[index];
            ll fr=mp[num]-1;
            if(fr<0)return;
                // cout<<index<<endl;
                ll pv=(fr*(fr-1))>>1;
                cnt_pr-=pv;
                ll nw=(fr*(fr+1))>>1;
                cnt_pr+=nw;
                // cout<<cnt_pr<<endl;
            
        };
        auto dec=[&](int index)->void{
            int num=nums[index];
            ll fr=mp[num];
            if(fr<0)return ;
                // cout<<index<<endl;
                ll pv=(fr*(fr+1))>>1;
                cnt_pr-=pv;
                ll nw=(fr*(fr-1))>>1;
                cnt_pr+=nw;
                // cout<<cnt_pr<<endl;
            
        };
       
        int start=0,end=0;
        while(end<=n&&start<n){
            // cout<<start<<end<<endl;
            while(cnt_pr<k&&end<n){
                mp[nums[end]]++;
                inc(end);
                end++;
            }
            
            // cout<<start<<end<<endl;
            if(cnt_pr>=k)add(end-1);
            // cout<<cnt_pr<<endl;
            // cout<<ans<<endl;
            mp[nums[start]]--;
            dec(start);
            // cout<<cnt_pr<<endl;
            start++;
        }


     return ans;   
    }
};