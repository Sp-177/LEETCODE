class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat[0].size(),m=mat.size();
        int low=0,high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            int maxi=0;
            int row=0;
            for(int i=0;i<m;i++){
                if(maxi<mat[i][mid]){
                    row=i;
                    maxi=mat[i][mid];
                }
            }
            bool lhs=mid-1<0?true:mat[row][mid-1]<maxi?true:false;
            bool rhs=mid+1>=n?true:mat[row][mid+1]<maxi?true:false;
            if(lhs&&rhs)return {row,mid};
            else if(lhs){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return {};
    }
};