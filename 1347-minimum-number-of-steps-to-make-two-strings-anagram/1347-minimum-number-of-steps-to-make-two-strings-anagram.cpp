class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int>s_m;
        int ans=0;
        for(auto i:s)s_m[i]++;
        for(auto i:t)s_m[i]--;
        for(auto i:s_m)if(i.second<0){ans+=abs(i.second);}
        return ans;
    }
};