class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>t;
        for(int i=0;i<nums.size();i++){
            
            
            
            if(t.size()==0){t.push_back(nums[i]);}
            else{
                int n=t.size();
                bool s=true;
                for(int j=0;j<n;j++){
                if(abs(nums[i]-t[j])>k)s=false;
                }
                if(s)t.push_back(nums[i]);
            }
            if(t.size()==3){ans.push_back(t);t.clear();}
        }
        
        if(ans.size()*3!=nums.size())ans.clear();
        return ans;

    }
};