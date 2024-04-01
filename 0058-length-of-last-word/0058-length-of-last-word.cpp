class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans=0;
        bool f=false;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]!=' '){f=true;ans++;}
            if(s[i]==' '&&f)return ans;
        }
        return ans;
    }
};