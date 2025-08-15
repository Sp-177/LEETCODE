#define ll long long
class Solution {
public:
    ll earliestSecondToMarkIndices(vector<int>& nums, vector<int>& c) {
        ll n=nums.size(),m=c.size();
        ll low=accumulate(nums.begin(),nums.end(),0LL)+n;
        ll high=m;
        ll ans=-1;
        auto pd=[&](ll mid)->bool{
            unordered_map<ll ,ll >last;
            vector<pair<ll ,ll >>vec;
            for(ll i=0;i<mid;i++){
                last[c[i]-1]=i;
            }
            if(last.size()<n)return 0;
            for(auto &[ind,index]:last){
                vec.push_back({index,ind});
            }
            sort(vec.begin(),vec.end());
            ll have=0;
            ll cnt=0;
            ll l_i=-1;
            for(auto&[index,ind]:vec){
                have+=index-l_i-1;
                ll num=nums[ind];
                if(have-num<0)return 0;
                have-=num;
                l_i=index;
                cnt++;
            }
            return cnt==n;
        };
        while(low<=high){
            ll mid=(low+high)>>1;
            if(pd(mid)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};