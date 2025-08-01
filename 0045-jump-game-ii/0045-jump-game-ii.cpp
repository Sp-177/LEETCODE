class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n==1||nums[0]==0)return 0;
        int ans=1;
        int start=1,end=nums[0];
        for(int i=1;i<n;){
            if(end>=n-1||start>=n-1)break;
            int maxi=end+1;
            while(start<=end){
                maxi=max(maxi,start+nums[start]);
                start++;
            }
            start=end+1;
            end=maxi;
            ans++;
            i=start;
        }
        return ans;


    }
};