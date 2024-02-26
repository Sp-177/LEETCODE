#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    void sol(vector<int>&v,int i,long long&ans,vector<int>&output){
        
        if(output.size()==3){
            if(output[0]*output[1]*output[2]!=0){
            if(output[0]==output[1]&&output[1]==output[2])ans++;
            else if(output[0]==output[1]||output[1]==output[2]||output[0]==output[2])ans++;
            else if(output[0]+output[1]>output[2]&&output[1]+output[2]>output[0]&&output[2]+output[0]>output[1])ans++;
            }return;
        }if(i==v.size())return;
        output.push_back(v[i]);
        sol(v,i+1,ans,output);
        output.pop_back();
        sol(v,i+1,ans,output);
    }
};
int main(){
    int t;cin>>t;
    for (int i = 0; i <t; i++)
    {
        int n;cin>>n;
        vector<int>v(n);
        for (int j = 0; j < n; j++)
        {
            cin>>v[j];
        }
        long long ans=0;
        vector<int>output;
        Solution S;
        S.sol(v,0,ans,output);
        cout<<ans<<endl;


        
    }
    
    return 0;
}