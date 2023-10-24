class Solution {
public:
    bool checkPowersOfThree(int n) {
        int x=0;
        while(pow(3,x)<=n){
            x++;
        }
        vector<int>dp(x,0);
        for(int i=0;i<x;i++){
            dp[i]=pow(3,i);
            
        }
        for(int i=x-1;i>=0;i--){
            if(n==0 || n==dp[i]){return true;}
            if(n>=dp[i]){n=n-dp[i];}
        }
        return false;
    }
};