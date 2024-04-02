class Solution {
public:
    bool isIsomorphic(string s, string t) {
        bool  ans=true;
        unordered_map<char,char>m;
        unordered_set<char>S;
        for(int i=0;i<s.size();i++){
            if(m.find(s[i])==m.end()){
                if(S.find(t[i])==S.end()){
                m[s[i]]=t[i];
                S.insert(t[i]);
                }
                else return false;
                }
            else if(m[s[i]]!=t[i])return false;
        }
        return ans;
    }
};