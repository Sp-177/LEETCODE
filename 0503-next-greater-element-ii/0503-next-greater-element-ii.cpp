class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>st2;
        int n=nums.size();
        vector<int>arr(n,-1);
        int maxi=INT_MIN;
        for(int i=0;i<n;i++)nums.push_back(nums[i]);
        for(int i=2*n-1;i>=0;i--){
            while(st2.size()&&st2.top()<=nums[i])st2.pop();
            if(i<n){
            if(st2.size())arr[i]=st2.top();}
            st2.push(nums[i]);
        }
        return arr;
    }
};