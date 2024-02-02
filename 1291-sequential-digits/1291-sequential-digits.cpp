class Solution {
public:
    void func(int low,int high,int i,vector<int>&ans){
        if(i>high)return;
        if(i>=low &&i<=high){ans.push_back(i);}
        int x=i%10;
        if(x==9)return;
        func(low,high,i*10+(x+1),ans);
    } 
    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
        for(int i=1;i<=9;i++)func(low,high,i,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};