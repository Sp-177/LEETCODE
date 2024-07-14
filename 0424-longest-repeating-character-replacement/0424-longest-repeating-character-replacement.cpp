class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char,int>m;
        int i=0,j=0,ans=0,n=s.size();
        while(i<n&&j<n){
            m[s[j]]++;
            int maxf=0;
            
            for(auto k:m){maxf=max(maxf,k.second);}
            while(j-i+1-maxf>k){
                m[s[i]]--;
                 for(auto k:m){maxf=max(maxf,k.second);}
                i++;
            }
            ans=max(j-i+1,ans);
            j++;
        }
        return ans;
    }
};