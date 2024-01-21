class Solution {
public:
    
    int rob(vector<int>& nums) {
        
        int i_1=nums[0];
        int i_2=0;
        for(int i=1;i<nums.size();i++){
            int t=0;
            if(i-2>=0)t=i_2;
            int n_t=i_1;
            i_2=i_1;
            i_1=max(t+nums[i],n_t);
        }
        return i_1;
    }
};