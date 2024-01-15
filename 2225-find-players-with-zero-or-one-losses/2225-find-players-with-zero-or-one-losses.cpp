class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,vector<bool>>m;
        for(auto i:matches){
            m[i[0]].push_back(true);
            m[i[1]].push_back(false);
        }
        vector<vector<int>>ans(2,vector<int>());
        for(auto i:m){
            int l=0;
            for(auto j:i.second){
                if(!j)l++;
            }
            if(l==0)ans[0].push_back(i.first);
            else if(l==1)ans[1].push_back(i.first);
        }
        sort(ans[0].begin(),ans[0].end());
        sort(ans[1].begin(),ans[1].end());
        return ans;
    }
};