class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
     vector<int>ans(pref.size(),0);
     int a=pref[0];
     ans[0]=a;
     for(int i=1;i<pref.size();i++){
         ans[i]=pref[i]^pref[i-1];
     }
     return ans;   
    }
};