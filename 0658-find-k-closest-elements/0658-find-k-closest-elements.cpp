class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
         int n=arr.size();
        vector<vector<int>>v(n,vector<int>(2));
        for(int i=0;i<n;i++){
            v[i][0]=abs(arr[i]-x);
            v[i][1]=i;
        }
        sort(v.begin(),v.end());
        vector<int>ans(k);
        for(int i=0;i<k;i++){
            ans[i]=arr[v[i][1]];
        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};