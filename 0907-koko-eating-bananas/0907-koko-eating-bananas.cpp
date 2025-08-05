#define ll long long
class Solution {
public:
    ll minEatingSpeed(vector<int>& piles, ll h) {
        ll n=piles.size();
        sort(piles.begin(),piles.end());
        ll low=1,high=piles[n-1];
        auto predicate=[&](ll eat)->bool{
            ll cnt=0;
            for(ll i=0;i<n;i++){
                cnt+=(piles[i]+eat-1)/eat;
            }
            return cnt<=h;
        };
        while(low<=high){
            ll mid=(low+high)>>1;
            if(predicate(mid))high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};