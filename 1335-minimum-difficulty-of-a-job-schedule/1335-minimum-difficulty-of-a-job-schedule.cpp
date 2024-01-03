class Solution {
public:
    int func(vector<int>&jobDifficulty,int d,int i,int d_i,vector<vector<int>>&dp){
        if(i==jobDifficulty.size() )return 0;
        else if(d-d_i>jobDifficulty.size()-i ||d==d_i)return -1;
        if(dp[i][d_i]!=-1)return dp[i][d_i];
        int ans=INT_MAX;int x=0;
        for(int j=i;j<=jobDifficulty.size()-(d-d_i);j++){
            x=max(x,jobDifficulty[j]);
            int y=func(jobDifficulty,d,j+1,d_i+1,dp);
            if(y==-1)continue;
            ans=min(ans,x+y);
        }
        return dp[i][d_i]=ans;
        
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        vector<vector<int>>dp(jobDifficulty.size(),vector<int>(d,-1));
        return func(jobDifficulty,d,0,0,dp);
    }
};