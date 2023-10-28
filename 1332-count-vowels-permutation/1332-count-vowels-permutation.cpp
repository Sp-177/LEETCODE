class Solution {
public:
    int countVowelPermutation(int n) {
        if(n==1){return 5;}
        long long mod=1e9+7;
        vector<long long>dp1(5,1);
        for(int i=2;i<=n;i++){
            vector<long long>dp2(5,0);
            dp2[0]=(dp1[1]+dp1[2]+dp1[4])%mod;
            dp2[1]=(dp1[0]+dp1[2])%mod;
            dp2[2]=(dp1[1]+dp1[3])%mod;
            dp2[3]=dp1[2]%mod;
            dp2[4]=(dp1[2]+dp1[3])%mod;
            dp1=dp2;
        }
        return  (dp1[0]+ dp1[1]+ dp1[2]+ dp1[3]+ dp1[4])%mod;
    }
};