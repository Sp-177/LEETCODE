class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>m;
        int start=0,end=0,maxf=0,len=0;
        while(end<s.size()){
            maxf=0;
            m[s[end]-'A']++;
            for(auto i:m){
                maxf=max(maxf,i.second);
            }
            if(end-start+1 -maxf<=k){
                len=max(len,end-start+1 );
            }
            else{
                m[s[start]-'A']--;
                start++;
            }
            end++;
        }
        return len;
    }
};