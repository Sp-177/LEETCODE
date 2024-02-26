#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int gcd(vector<int>&v){
        int ans=v[0];
        for(int i=1;i<v.size();i++){
            ans=__gcd(ans,v[i]);
        }
        return ans;
    }
        int sol(int x,int y,vector<int>&v,vector<vector<int>>&dp){
            //cout<<x<<y<<endl;
            if(y<0)return 0;
            if(y==0){
                v.push_back(x);
                int ans=gcd(v);
                v.pop_back();
                return ans;

            }
            if(dp[x][y]!=-1)return dp[x][y];
            int ans=0;
            for(int i=1;i<=x-y;i++){
                v.push_back(i);
                ans=max(ans,sol(x-i,y-1,v,dp));
                v.pop_back();
            }
            return dp[x][y]=ans;

        }
};
int main(){
    int t;cin>>t;
    for(int i=0;i<t;i++){
        int x,y;cin>>x>>y;
        vector<int>v;
        Solution s;
        vector<vector<int>>dp(x+1,vector<int>(y,-1));
        cout<<s.sol(x,y-1,v,dp)<<endl;
    }
    return 0;
}