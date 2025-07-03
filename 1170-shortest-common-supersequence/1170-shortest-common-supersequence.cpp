class Solution {
public:
    vector<vector<int>>dp;
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.size(),m=str2.size();
        dp.resize(n+1,vector<int>(m+1,0));
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(str1[i]==str2[j])dp[i][j]=1+dp[i+1][j+1];
                else dp[i][j]=max(dp[i][j+1],dp[i+1][j]);
            }
        }
        string lcs="";
        int i=0,j=0;
        while(i<n&&j<m){
            if(str1[i]==str2[j]){
                lcs+=str1[i];
                i++;j++;
            }
            else{
                if(dp[i+1][j]>dp[i][j+1]){
                   
                    i++;
                }
                else {
                   
                    j++;
                }
            }
        }
        string ans="";
        i=0,j=0;
        int ind=0;
        
        while(i<=n&&j<=m&&ind<lcs.size()){
            // cout<<i<<" "<<j<<" "<<ind<<endl;
            while(i<n&&str1[i]!=lcs[ind]){
                ans+=str1[i];
                i++;
            }
            if(str1[i]==lcs[ind])i++;
            while(j<m&&str2[j]!=lcs[ind]){
                ans+=str2[j];
                j++;
            }
            if(str2[j]==lcs[ind])j++;
            ans+=lcs[ind];
            ind++;
        }
        while(i<n)ans+=str1[i++];
        while(j<m)ans+=str2[j++];
        return ans;
    }
};