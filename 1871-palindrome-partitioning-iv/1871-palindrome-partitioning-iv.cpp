class Solution {
public:
    vector<vector<bool>>is;
    vector<vector<int>>dp;
    bool func(string&s,int n,int k,int index){
        // cout<<index<<" "<<k<<endl;
        if(k==0){
            if(index==n)return true;
            return false;
        }
        if(dp[index][k]!=-1)return dp[index][k];
        bool ans=false;
        for(int i=index;i<=n-k;i++){
            if(is[index][i]){
            ans=ans||func(s,n,k-1,i+1);
            }
        }
        return dp[index][k]=ans;
    }
    bool checkPartitioning(string s) {
        int n=s.size();
        is.resize(n,vector<bool>(n,false));
        dp.resize(n,vector<int>(4,-1));
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(s[i]==s[j] &&(j-i<=2 || is[i+1][j-1])){
                    is[i][j]=true;
                }
            }
        }
        return func(s,n,3,0);
    }
};