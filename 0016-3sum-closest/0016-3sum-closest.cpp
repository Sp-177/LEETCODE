class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int dif=INT_MAX,ans=0,n=nums.size();
        for(int i=0;i<nums.size();i++){
            int start=i+1,end=n-1;
            while(start<end){
                int sum=nums[i]+nums[start]+nums[end];
                if(abs(sum-target)<=dif){
                    dif=abs(sum-target);
                    ans=sum;
                }
                if(sum==target){return target;}
                else if(sum>target){end--;}
                else {start++;}
            }
        }return ans;
    }
};