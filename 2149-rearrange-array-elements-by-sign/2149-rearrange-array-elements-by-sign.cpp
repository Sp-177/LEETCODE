class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>ans(nums.size());
        int x=0;
        int y=1;
        for(int i:nums){
            if(i>0){ans[x]=i;x+=2;}
            else {ans[y]=i;y+=2;}
        }
        return ans;
    }
};