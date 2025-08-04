class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        int pos=0,neg=0;
        int fill=0;
        while(fill<n){
            if(fill&1){
                while(neg<n&&nums[neg]>0)neg++;
                ans[fill]=nums[neg++];
            }
            else{
                while(pos<n&&nums[pos]<0)pos++;
                ans[fill]=nums[pos++];
            }
            fill++;
        }
        return ans;
    }
};