class Solution {
public:
    int appendCharacters(string s, string t) {
        int i=0,j=0,ans=0;
        while(i<s.size()&&j<t.size()){
            if(s[i]==t[j]){j++;ans++;}
            i++;
        }
        return t.size()-ans;

    }
};