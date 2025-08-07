class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        unordered_map<int,int>ans;
        vector<int>vec;
        int n=nums2.size();
        for(int i=n-1;i>=0;i--){
            while(st.size() && nums2[i]>st.top())st.pop();
            ans[nums2[i]]=(st.size()==0)?-1:st.top();
            st.push(nums2[i]);
        }
        for(int i:nums1)vec.push_back(ans[i]);
        return vec;
    }
};