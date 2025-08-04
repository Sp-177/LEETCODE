class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size(),m=t.size();
        if(m>n)return "";
        int cnt=m;
        unordered_map<char,int>freq;
        for(char c:t)freq[c]--;
        int start=0,end=0;
        int ans=INT_MAX;
        int l=-1,r=-1;
        while(start<n){
            while(cnt>0&&end<n){
                freq[s[end]]++;
                if(freq[s[end]]<=0)cnt--;
                end++;
            }
            if(cnt==0){
                if(ans>end-start){
                    ans=end-start;
                    r=end;
                    l=start;
                }
            }
            freq[s[start]]--;
            if(freq[s[start]]<0)cnt++;
            start++;
        }
        if(ans==INT_MAX)return "";
        return s.substr(l,r-l);
    }
};