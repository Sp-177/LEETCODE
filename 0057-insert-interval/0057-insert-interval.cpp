class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& iv, vector<int>& ni) {
        iv.push_back(ni);
        sort(iv.begin(),iv.end());
        vector<vector<int>>ans;
        ans.push_back(iv[0]);
        for(int i=1;i<iv.size();i++){
            int last=ans.back()[1];
            if(iv[i][0]<=last){
                ans.back()[1]=max(last,iv[i][1]);
            }
            else{
                ans.push_back(iv[i]);
            }
        }
        return ans;
    }
};