class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
         int row=0;
         while(row<matrix.size()){
            auto i=matrix[row];
            auto it=lower_bound(i.begin(),i.end(),target);
            if(it!=i.end()&&i[it-i.begin()]==target)return true;
            row++;
         }
         return false;
    }
};