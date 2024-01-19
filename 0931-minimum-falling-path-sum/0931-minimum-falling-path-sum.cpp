class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        for(int i=matrix.size()-2;i>=0;i--){
            for(int j=0;j<matrix[i].size();j++){
                int l=INT_MAX,r=INT_MAX;
                if(j-1>=0){l=matrix[i+1][j-1];}
                if(j+1<matrix.size())r=matrix[i+1][j+1];
                matrix[i][j]+=min(matrix[i+1][j],min(l,r));
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<matrix[0].size();i++)ans=min(ans,matrix[0][i]);
        return ans;
    }
};