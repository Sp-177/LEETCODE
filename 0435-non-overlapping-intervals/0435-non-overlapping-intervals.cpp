class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b){
        if(a[1]<b[1]){return true;}
        else if(a[1]==b[1]){
            return a[0]<b[0];
        }
        return false;
    }   
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        // for(auto i:intervals){cout<<i[0]<<' '<<i[1]<<endl;}
        int ans=0,end=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<end){ans++;}
            else{
                end=intervals[i][1];
            }
        }
        return ans;

    }
};