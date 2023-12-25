class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>>dp(query_row+1,vector<double>());
        for(int i=0;i<query_row+1;i++){
            dp[i].resize(i+1);
        }
        dp[0][0]=poured;
        for(int i=1;i<=query_row;i++){
            for(int j=0;j<=i;j++){
                double x=0,y=0;
                if(j<=i-1 &&dp[i-1][j]>1){
                     x=(dp[i-1][j]-1)/2;}
                    
                if(j-1>=0&&dp[i-1][j-1]>1){
                    y=(dp[i-1][j-1]-1)/2;
                    dp[i-1][j-1]=1;
                }
                    dp[i][j]=x+y;
                    
                }
            }
        
        if(dp[query_row][query_glass]>1){return 1;}
        return dp[query_row][query_glass];
    }
};