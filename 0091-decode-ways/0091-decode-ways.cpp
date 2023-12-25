class Solution {
public:
    int func(string s,int i,vector<int>&dp){
        if(i<0){return 1;}
        if(dp[i]!=-1)return dp[i];
        int s_i=0;
        if(s[i]!='0'){
        s_i=func(s,i-1,dp);}
        int d=0;
        if(i>=1 && ((s[i-1]=='2' && s[i]<='6') ||(s[i-1]=='1' && s[i]<='9'))){
            d=func(s,i-2,dp);
        }
        return dp[i]=s_i+d;
    }
    int numDecodings(string s) {
        vector<int>dp(s.size(),-1);
        return func(s,s.size()-1,dp);
    }
};