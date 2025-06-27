class Solution {
public:
    vector<vector<int>>dp;
    int cntPal(string &s,int i,int j){
        int ans=0;
        while(i<j){
            if(s[i]!=s[j])ans++;
            i++;j--;
        }
        return ans;
    }
    int func(string&s,int k,int index){
        if(index==s.size())return 0;
        if(k==1){
            return cntPal(s,index,s.size()-1);
        }
        if(dp[index][k]!=-1)return dp[index][k];
        int ans=INT_MAX;
        int len=s.size() -k+1;
        // cout<<index<<" "<<k<<endl<<len<<endl;
        for(int i=index;i<len;i++){
            int cnt=cntPal(s,index,i);
            int sum=func(s,k-1,i+1);
            if(sum!=INT_MAX)ans=min(ans,sum+cnt);
        }
        return dp[index][k]=ans;
    } 
    int palindromePartition(string s, int k) {
        dp.resize(s.size(),vector<int>(k+1,-1));
        return func(s,k,0);
    }
};