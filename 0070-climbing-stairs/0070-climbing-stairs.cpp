class Solution {
public:

    int climbStairs(int n) {
        int N_1=1,N_2=0;
        int ans=0;
        for(int i=n-1;i>=0;i--){
            ans=N_1+N_2;
            N_2=N_1;
            N_1=ans;
        }
        return ans;
    }
};