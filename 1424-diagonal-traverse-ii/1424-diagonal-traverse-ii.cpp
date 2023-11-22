class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<vector<int>>output;
        int size=-1;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums[i].size();j++){
                if(size<i+j){
                    vector<int>v;
                    output.push_back(v);
                    size=i+j;
                    }
                    output[i+j].push_back(nums[i][j]);
            }
        }
        vector<int>ans;
        for(int i=0;i<output.size();i++){
            for(int j=output[i].size()-1;j>=0;j--){
                ans.push_back(output[i][j]);
            }
        }
        return ans;
    }
};