class Solution {
public:
    bool canJump(vector<int>& nums) {
        bool can=true;
        int n=nums.size();
        int index=-1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]==0&&can){
                can=false;
                index=i;
            }
            else {
                if(i+nums[i]>index)can=true;
            }
        }
        return can;
    }
};