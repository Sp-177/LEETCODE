#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 int main(){
    int t;cin>>t;
    while(t>0){
        int s;cin>>s;
        string ans="";
        unordered_map<int,int>m;
        m[0]=97;
        for(int i=0;i<s;i++){
            int x;cin>>x;
            ans+=char(m[x]);
            m[x+1]=m[x];
            m[x]=x+1;
        }
        cout<<ans<<endl;
    }
    return 0;
 }