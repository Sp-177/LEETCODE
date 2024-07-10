class Solution {
public:
    int sol(string s,int start,int end){
        int out=0;
        while(start>=0&&end<s.size()&&s[start]==s[end]){
            start--;end++;
            out++;
        }
        return out;
    }
    int countSubstrings(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            ans+=sol(s,i,i);
            ans+=sol(s,i,i+1);
        }

        return ans;
    }
};