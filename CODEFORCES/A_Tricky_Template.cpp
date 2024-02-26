#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    for(int i=0;i<t;i++){
        int n;cin>>n;
        string a,b,c;
        cin>>a>>b>>c;
        int ans=0;
        if(a==c||b==c){ans=n;}
        else{
        for(int j=0;j<n;j++){
            if(a[j]==c[j]||b[j]==c[j]){ans++;}
        }}
        if(ans!=n)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;        
    }
}