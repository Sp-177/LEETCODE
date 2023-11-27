class Solution {
public:
    long long knightDialer(int n) {
        if(n==1){return 10;}
        vector<long long>ans(10,1);
        vector<long long>temp=ans;
        long long mod=1e9+7;
        for(int i=1;i<n;i++){
            ans[0]=(temp[4]+temp[6])%mod;
            ans[1]=(temp[8]+temp[6])%mod;
            ans[2]=(temp[7]+temp[9])%mod;
            ans[3]=(temp[4]+temp[8])%mod;
            ans[4]=(temp[3]+temp[9]+temp[0])%mod;
            ans[6]=(temp[1]+temp[7]+temp[0])%mod;
            ans[7]=(temp[2]+temp[6])%mod;
            ans[8]=(temp[1]+temp[3])%mod;
            ans[9]=(temp[4]+temp[2])%mod;
            temp=ans;
        }
        return (ans[0]+ans[1]+ans[2]+ans[3]+ans[4]+ans[6]+ans[7]+ans[8]+ans[9])%mod;
        
    }
};