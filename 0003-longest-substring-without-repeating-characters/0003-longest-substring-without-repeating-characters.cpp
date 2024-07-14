class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int>m;
        int ans=0;
        int n=s.size();
        int start=0,end=0;
        while(start<n&&end<n){
            if(m[s[start]]==1){
                while(m[s[start]]==1&&end<start){
                    m[s[end]]--;
                    end++;
                }
                m[s[start]]++;
            }
            else{
                m[s[start]]++;
            }
            ans=max(ans,start-end+1);
            start++;
        }

        return ans;
    }
};