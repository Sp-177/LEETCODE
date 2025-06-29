class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>ans(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0)ans[i]=max(ans[i],ans[j]+1);
            }
        }
        for(int i:ans)cout<<i<<" ";
        int m=*max_element(ans.begin(),ans.end());
        int maxi=m;
        int num=1;
        vector<int>out;
        // cout<<maxi<<endl;
        for(int i=n-1;i>=0;i--){
           
            if((ans[i]==m && (num%nums[i]==0) )|| (ans[i]==maxi&&ans[i]==m)){
                m--;
                num=nums[i];
                out.push_back(nums[i]);
            }
        }
        return out;
    }
};