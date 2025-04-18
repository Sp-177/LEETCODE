
class Solution {
public:
    string countAndSay(int n) {
        vector<string>dp(n+1);
        dp[1]="1";
        auto rle=[&](string str)->string{
            string ans="";
            for(int i=0;i<str.size();){
                int cnt=0;
                int ind=i;
                while(str[i]==str[ind]&&i<str.size()){
                    i++;
                    cnt++;
                }
                ans+=to_string(cnt)+str[ind];
            }
            return ans;
        };
        for(int i=2;i<=n;i++){
            dp[i]=rle(dp[i-1]);
        }
        return dp[n];        
    }
};