#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    for(int i=0;i<t;i++){
        int x,y;cin>>x>>y;
        string s;
        int a=0,f=1;
        for(int j=0;j<y;j++){
            s+=char(j+'a');
        }
        for(int j=1;j<x;j++){
            s+=s;
        }
        cout<<s<<endl;
    }
    return 0;
}