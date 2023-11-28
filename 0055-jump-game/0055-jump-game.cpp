class Solution {
public:
    bool canJump(vector<int>& nums) {
    int last_index=nums.size()-1;
    bool flag=true;
        for(int i=last_index-1;i>=0;i--){
            if(nums[i]>=last_index-i){last_index=i;flag=true;}
            else{flag=false;}
        }
        return flag;
    }
};