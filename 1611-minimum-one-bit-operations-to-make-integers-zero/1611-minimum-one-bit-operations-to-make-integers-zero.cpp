class Solution {
    private:
        int family(int n){
            int a=log2(n);
            if(pow(2,a)!=n){return pow(2,floor(a));}
            return n;
        }
        int func(int n,unordered_map<int,int>&ans){
            if(n==0){return 0;}
            if(ans.count(n)!=0){return ans[n];}
            else{
                
                int f=family(n);
                int sub=n-f;
                if(f==n){
                    ans[n]=n+func(n/2,ans);
                }
                else{
                    ans[n]=func(f,ans)-func(sub,ans);
                }
                return ans[n];
            }
        }
public:
    int minimumOneBitOperations(int n) {
        unordered_map<int,int>ans;
        ans[0]=0;
        ans[1]=1;
        return func(n,ans);
    }
};