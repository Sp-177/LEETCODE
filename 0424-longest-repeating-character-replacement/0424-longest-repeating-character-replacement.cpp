class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char,int>m;
        int ans=0,l=0,r=0;
        while(r<s.size()){
            m[s[r]]++;
            int maxi=0,sum=0;
            for(auto i:m){
                sum+=i.second;
                maxi=max(maxi,i.second);
            }
            while(k<sum-maxi){
                m[s[l]]--;
                if(m[s[l]]==0){m.erase(s[l]);}
                sum=0,maxi=0;
                 for(auto i:m){
                sum+=i.second;
                maxi=max(maxi,i.second);
            }
                l++;
            }
            
            ans=max(ans,r-l+1);
            r++;
        }return ans;
    }
};