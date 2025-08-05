class Solution {
public:
    int shipWithinDays(vector<int>& w, int days) {
        int n=w.size();
        int low=*max_element(w.begin(),w.end()),high=accumulate(w.begin(),w.end(),0);
        auto p=[&](int m)->bool{
           int cnt=1;
           int sum=0;
           for(int i:w){
            if(sum+i<=m)sum+=i;
            else {
                cnt++;
                sum=i;
            }
           }
           return cnt<=days;
        };
        while(low<=high){
            int mid=(low+high)>>1;
            if(p(mid))high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};