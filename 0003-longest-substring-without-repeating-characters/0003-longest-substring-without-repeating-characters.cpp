class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<int,int>m;
        int len=0,ans=0,end=0,start=0;
        while(end<s.size()&&start<s.size()){
            if(m[s[end]]!=0){
            
                while(m[s[end]]==1&&start<=end){
                    len--;
                    m[s[start]]--;
                    start++;
                }
            }
            m[s[end]]++;
            len++;
            ans=max(ans,len);
            end++;
        }
        return ans;
    }
};