class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int freq=1;
        int num=0;
        for(int i=0;i<nums.size();i++){
            
            if(num!=nums[i]){
                freq--;
            }
            else{
                freq++;
            }
            if(freq==0){
                num=nums[i];
                freq++;
            }
        }
        return num;
    }
};