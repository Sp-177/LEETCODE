class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix){
        int x=matrix.size();
        int y=matrix[0].size();
        vector<vector<int>>ans(y,vector<int>(x,0));
        for(int i=0; i<y;i++){
            for(int j=0;j<x;j++){
                ans[i][j]=matrix[j][i];
            }
        }return ans;

    }
};