class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& inv, vector<int>& ni) {
        inv.push_back(ni);
        sort(inv.begin(),inv.end());
        vector<vector<int>>ans;
        int start=inv[0][0],end=inv[0][1];
        int n=inv.size();
        for(int i=1;i<n;i++){
            int s=inv[i][0],e=inv[i][1];
            if(start<=s&&s<=end){
                end=max(e,end);
            }
            else{
                ans.push_back({start,end});
                start=s;end=e;
            }
        }
        ans.push_back({start,end});
        return ans;
    }
};