class Solution {
public:

    int numberOfSubstrings(string s) {
    map<char,int>m;int ans=0,n=s.size(),l=0;
    for(int i=0;i<n;i++){
        m[s[i]]++;
        while(m.size()==3){
            ans+=n-i;
            m[s[l]]--;
            if(m[s[l]]==0)m.erase(s[l]);
            l++;
        }
        }    
        return ans;
    }
};