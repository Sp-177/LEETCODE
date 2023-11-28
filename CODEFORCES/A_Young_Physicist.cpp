#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    bool equilibrium(vector<vector<int>>&force_vec){
        for(int i=0;i<3;i++){
            int a=0;
            for(int j=0;j<force_vec.size();j++){
                a+=force_vec[j][i];
            }
            if(a!=0){return false;}
        }
        return true;
    }

};
int main(){
    int tc;
    cin>>tc;
    vector<vector<int>>force_vec(tc,vector<int>(3));
    for(int c=0;c<tc;c++){
        
            int x,y,z;
            cin>>x>>y>>z;
            force_vec[c][0]=x;force_vec[c][1]=y;force_vec[c][2]=z;
        
    }
    Solution sol;
    if(sol.equilibrium(force_vec)){cout<<"YES";}
    else{cout<<"NO";}
    return 0;
}
