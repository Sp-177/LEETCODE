class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int MAX1=INT_MIN;
        int MAX2=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>MAX1){
                MAX2=MAX1;
                MAX1=nums[i];
            }
            else if(nums[i]>MAX2){
                MAX2=nums[i];
            }
        }
        return (MAX1-1)*(MAX2-1);
    }
};