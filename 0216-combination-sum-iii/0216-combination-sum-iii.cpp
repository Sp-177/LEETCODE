class Solution {
public:
    void solve(vector<vector<int>>&ans,vector<int>&ds,int k,int n,int idx){
        if(k == 0 || n == 0){
            if(k == 0 && n == 0)
                ans.push_back(ds);
            return;
        }
        for(int i = idx ; i <= 9 ; i++){
            // if(n < i) return;
            ds.push_back(i);
            solve(ans,ds,k-1,n-i,i+1);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;

        solve(ans,ds,k,n,1);
        return ans;
    }
};