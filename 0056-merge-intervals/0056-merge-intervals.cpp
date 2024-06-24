class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& interval) {
        sort(interval.begin(),interval.end());
        vector<vector<int>>ans;
        int start=interval[0][0],end=interval[0][1];
        for(int i=0;i<interval.size();i++){
            if(start<=interval[i][0] && interval[i][0]<=end){
                end=max(end,interval[i][1]);
            }
            else{
                ans.push_back({start,end});
                start=interval[i][0];
                end=interval[i][1];
            }

        }
         ans.push_back({start,end});
        return ans;
    }
};