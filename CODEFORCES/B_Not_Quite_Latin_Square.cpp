#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
        char sol(vector<int>&v){
            for(int i=0;i<3;i++){
                if(v[i]!=3)return i+65;
            }
        }
};
int main(){
    int t;cin>>t;
    for(int i=0;i<t;i++){
        vector<int>v(3);
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                char x;cin>>x;
                if(x=='?')continue;
                v[int(x)-65]++;
            }
        }
        Solution s;
        cout<<s.sol(v)<<endl;
    }
    return 0;
}