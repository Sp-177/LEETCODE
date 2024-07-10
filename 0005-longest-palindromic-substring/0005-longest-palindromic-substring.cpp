class Solution {
public:
     string helper(string &s,int start,int end){
        string out="";
        int n=s.size();
        while(start>=0&&end<n&&s[start]==s[end]){
                
                out+=s[end];
                if(start!=end)out=s[start]+out;
                start--;end++;
            }
        return out;
     }
    string longestPalindrome(string s) {
        int n=s.size();
        string ans="";
        for(int i=0;i<n;i++){
            
            string out=helper(s,i,i);
            if(out.size()>=ans.size()){ans=out;}
            string out1=helper(s,i,i+1);
            if(out1.size()>=ans.size()){ans=out1;}

            
        }
        return ans;
    }
};