class Solution {
public:
    int numberOfSubstrings(string s) {
      int ans=0,i=0,j=0,n=s.size();
      map<char,int>m;
      while(i<n&&j<n){
        m[s[j]]++;
        while(m.size()==3){
            ans+=n-j;
            m[s[i]]--;
            if(m[s[i]]<=0){m.erase(s[i]);}
            i++;
        }
        j++;
      }
    return ans;

    }
};