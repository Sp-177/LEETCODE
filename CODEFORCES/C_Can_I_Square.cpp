#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
        bool sol(int ans){
            int x=floor(sqrt(ans));
            if(ans==x*x)return true;
            return false;
        }
};
int main(){
    int t;cin>>t;
    for(int i=0;i<t;i++){
        int b;cin>>b;
        int v=0;
        for(int j=0;j<b;j++){
            int temp;cin>>temp;
            v+=temp;
        }
        Solution s;
        bool x=s.sol(v);
        if(x)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}