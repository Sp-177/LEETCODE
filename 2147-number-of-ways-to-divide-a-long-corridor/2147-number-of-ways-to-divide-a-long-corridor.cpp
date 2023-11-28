class Solution {
public:
    int numberOfWays(string corridor) {
        int count_seat=0;
        int last_index=0;
        long long ans=1;
        long long mod=1e9+7;
        for(int i=0;i<corridor.size();i++){
            if(corridor[i]=='S'){
                count_seat++;
                if(count_seat%2==0){last_index=i;}
                else if(count_seat!=1){
                    ans=((ans%mod)*(i-last_index))%mod;
                }
            }
        }
        if(count_seat%2!=0 || count_seat==0){return 0;}
        return ans;
    }
};