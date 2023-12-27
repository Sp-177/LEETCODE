class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans=0;
        for(int i=1;i<colors.size();i++){
            if(colors[i]==colors[i-1]){
                int x=0;
                if(neededTime[i]<neededTime[i-1]){x=neededTime[i];neededTime[i]=neededTime[i-1];}
                else {x=neededTime[i-1];neededTime[i-1]=neededTime[i];}
                ans+=x;
            }
        }
        return ans;
    }
};