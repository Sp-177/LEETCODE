class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& inv) {
        auto cmp=[&](vector<int>&a,vector<int>&b)->bool{
            if(a[0]<b[0])return true;
            else if(a[0]==b[0])return a[1]<b[1];
            return false;
        };
        sort(inv.begin(),inv.end(),cmp);
        int start=inv[0][0],end=inv[0][1];
        vector<vector<int>>ans;
        int n=inv.size();
        for(int i=1;i<n;i++){
            int s=inv[i][0],e=inv[i][1];
            if(s<=end)end=max(e,end);
            else{
                ans.push_back({start,end});
                start=s;
                end=e;
            }
        }
        ans.push_back({start,end});
        return ans;
    }
};