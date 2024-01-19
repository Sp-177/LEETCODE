class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
         for(int i=matrix.size()-2;i>=0;i--){
            for(int j=0;j<matrix[i].size();j++){
                int d=INT_MAX;
                for(int k=0;k<matrix[i].size();k++){
                    if(k==j)continue;
                    d=min(d,matrix[i+1][k]);
                }
                matrix[i][j]+=d;
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<matrix[0].size();i++)ans=min(ans,matrix[0][i]);
        return ans;
        
    }
};