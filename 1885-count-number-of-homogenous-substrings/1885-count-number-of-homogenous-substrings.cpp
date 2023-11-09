class Solution {
private:
   
public:
    int countHomogenous(string s) {
        const long long mod=1e9+7;
        long long ans=1;
        long long len =1;
        for(int i=1;i<s.size();i++){
            if(s[i-1]==s[i]){
                len++;
            }
            else{
                len=1;
            }
            ans=(ans+len)%mod;
        }
        return ans;
    }
};