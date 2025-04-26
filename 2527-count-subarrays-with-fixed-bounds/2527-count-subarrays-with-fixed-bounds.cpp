#define ll long long
class Solution {
public:
    long long countSubarrays(vector<int>& nums, ll  minK, ll  maxK) {
        vector<vector<ll >>vec;
        vector<ll >temp;
        for(ll  i:nums){
            if(i>=minK && i<=maxK){
                temp.push_back(i);
            }
            else{
                vec.push_back(temp);
                temp.clear();
            }
        }
        vec.push_back(temp);
        auto calc=[&](vector<ll >&vec)->ll{
            ll  n= vec.size();
            ll  start=0,end=0;
            multiset<ll >ms;
            ll ans=0;
            while(start<n){
                end=max(end,start);
                while(!(*ms.begin()==minK && *ms.rbegin()==maxK)&&end<n){
                    ms.insert(vec[end++]);
                }

                if(*ms.begin()==minK&&*ms.rbegin()==maxK)ans+=n-end+1;
                // cout<<start<<" "<<end<<endl;
                auto it=ms.find(vec[start]);
                ms.erase(it);
                start++;
            }
            return ans;
        };
        ll ans=0;
        for(auto i:vec){
            for(auto j:i)cout<<j<<" ";
            cout<<endl;
            ans+=calc(i);
        }
        return ans;
    }
};