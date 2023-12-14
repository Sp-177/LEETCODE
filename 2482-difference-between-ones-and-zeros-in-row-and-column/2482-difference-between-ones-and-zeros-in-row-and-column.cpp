class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<int>OC(n,0);
        vector<int>OR(m,0);
        vector<int>ZC(n,0);
        vector<int>ZR(m,0);
        vector<vector<int>>ans(m,vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    ZR[i]++;
                    ZC[j]++;
                }
                else{
                    OR[i]++;
                    OC[j]++;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans[i][j]=OR[i]+OC[j]-ZR[i]-ZC[j];
            }
        }return ans;


    }
};