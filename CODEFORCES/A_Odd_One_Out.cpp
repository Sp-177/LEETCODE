#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
        int sol(int x,int y,int z){
            if(x==y)return z;
            else if(x==z)return y;
            else return x;
        }
};
int main(){
    int t;cin>>t;
    for(int i=0;i<t;i++){
        Solution s;
        int x,y,z;cin>>x>>y>>z;
        cout<<s.sol(x,y,z)<<endl;
    }
    return 0;
}