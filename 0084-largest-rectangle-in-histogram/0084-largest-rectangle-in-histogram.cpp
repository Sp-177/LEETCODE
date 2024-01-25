class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>dp;

        dp.push(0);
        int n=heights.size();
        int ans=0;
        for(int i=1;i<=n;i++){
            while(!dp.empty()){
                if(i!=n &&heights[i]==heights[dp.top()]){break;}
                if(i!=n && heights[i]>heights[dp.top()]){dp.push(i);break;}
                else{
                    int ci=dp.top();dp.pop();
                    int x;
                    if(dp.empty())x=i;
                    else x=i-dp.top()-1;
                    ans=max(ans,x*heights[ci]);
                }
            }
            dp.push(i);
        }
        return ans;
    }
};