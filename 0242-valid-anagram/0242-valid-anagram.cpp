class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()){return false;}
        unordered_map<char,int>s_m;
        unordered_map<char,int>t_m;
        for(int i=0;i<s.size();i++){
            s_m[s[i]]++;
            t_m[t[i]]++;
        }
        for(auto i:s_m){
            if(t_m[i.first]!=i.second){return false;}
        }
        return true;
    }
};