class Solution {
public:
    int trap(vector<int>& height) {
        int l_m=0,l=0,r_m=0;
        int r=height.size()-1;
        int ans=0;
        while(l<=r){
            if(height[l]<=height[r]){
                if(height[l]>=l_m)l_m=height[l];
                else ans+=l_m-height[l];
                l++;
            }
            else{
                if(height[r]>=r_m)r_m=height[r];
                else ans+=r_m-height[r];
                r--;
            }
        }
        return ans;
    }
};