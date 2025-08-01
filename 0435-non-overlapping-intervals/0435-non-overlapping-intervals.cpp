class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& inv) {
        auto cmp=[&](vector<int>&a,vector<int>&b)->bool{
            if(a[1]<b[1])return true;
            else if(a[1]==b[1])return a[0]<b[0];
            return false;
        };
        sort(inv.begin(),inv.end(),cmp);
        int start=inv[0][0],end=inv[0][1];
        int cnt=0;
        int n=inv.size();
        // for(auto i:inv)cout<<i[0]<<" "<<i[1]<<endl;
        for(int i=1;i<n;i++){
            int s=inv[i][0],e=inv[i][1];
            if(!(end<=s&&end<e)){
                cnt++;
                continue;
            }
            start=s;end=e;
        }
        return cnt;
    }
};